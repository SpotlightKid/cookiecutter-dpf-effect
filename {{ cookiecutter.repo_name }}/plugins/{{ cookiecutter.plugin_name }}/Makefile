#!/usr/bin/make -f
# Makefile for DISTRHO Plugins #
# ---------------------------- #
# Created by falkTX
#

# --------------------------------------------------------------
# Project name, used for binaries

NAME = {{ cookiecutter.plugin_name | lower }}

# --------------------------------------------------------------
# Plugin types to build

BUILD_LV2 ?= true
BUILD_VST2 ?= true
BUILD_JACK ?= true
BUILD_DSSI ?= false
BUILD_LADSPA ?= {{ "true" if cookiecutter.ui_type == "none" else "false" }}

# --------------------------------------------------------------
# Files to build

FILES_DSP = \
	Plugin{{ cookiecutter.plugin_name }}.cpp
{% if cookiecutter.ui_type != "none" %}
FILES_UI = \
	UI{{ cookiecutter.plugin_name }}.cpp
{% endif %}
# --------------------------------------------------------------
# Do some magic

include ../../dpf/Makefile.plugins.mk

# --------------------------------------------------------------
# Enable all selected plugin types

ifeq ($(BUILD_LV2),true)
ifeq ($(HAVE_DGL),true)
TARGETS += lv2_sep
else
TARGETS += lv2_dsp
endif
endif

ifeq ($(BUILD_VST2),true)
TARGETS += vst
endif

ifeq ($(BUILD_JACK),true)
ifeq ($(HAVE_JACK),true)
TARGETS += jack
endif
endif

ifeq ($(BUILD_DSSI),true)
ifeq ($(HAVE_DGL),true)
ifeq ($(HAVE_LIBLO),true)
TARGETS += dssi
endif
endif
endif

ifeq ($(BUILD_LADSPA),true)
TARGETS += ladspa
endif

all: $(TARGETS)

# --------------------------------------------------------------
