#!/usr/bin/make -f
# Makefile for DISTRHO Plugins #
# ---------------------------- #
# Created by falkTX, Christopher Arndt, and Patrick Desaulniers
#

# --------------------------------------------------------------
# Installation directories

PREFIX ?= /usr/local
BINDIR ?= $(PREFIX)/bin
LIBDIR ?= $(PREFIX)/lib
DSSI_DIR ?= $(LIBDIR)/dssi
LADSPA_DIR ?= $(LIBDIR)/ladspa
ifneq ($(MACOS_OR_WINDOWS),true)
LV2_DIR ?= $(LIBDIR)/lv2
VST_DIR ?= $(LIBDIR)/vst
endif
ifeq ($(MACOS),true)
LV2_DIR ?= /Library/Audio/Plug-Ins/LV2
VST_DIR ?= /Library/Audio/Plug-Ins/VST
endif
ifeq ($(WINDOWS),true)
LV2_DIR ?= $(COMMONPROGRAMFILES)/LV2
VST_DIR ?= $(COMMONPROGRAMFILES)/VST2
endif

USER_DSSI_DIR ?= $(HOME)/.dssi
USER_LADSPA_DIR ?= $(HOME)/.ladspa
ifneq ($(MACOS_OR_WINDOWS),true)
USER_LV2_DIR ?= $(HOME)/.lv2
USER_VST_DIR ?= $(HOME)/.vst
endif
ifeq ($(MACOS),true)
USER_LV2_DIR ?= $(HOME)/Library/Audio/Plug-Ins/LV2
USER_VST_DIR ?= $(HOME)/Library/Audio/Plug-Ins/VST
endif
ifeq ($(WINDOWS),true)
USER_LV2_DIR ?= $(APPDATA)/LV2
USER_VST_DIR ?= $(APPDATA)/VST
endif

# --------------------------------------------------------------
# Project name, used for binaries

NAME = {{ cookiecutter.plugin_name | lower }}

# --------------------------------------------------------------
# Plugin types to build

BUILD_LV2 ?= true
BUILD_VST2 ?= true
BUILD_JACK ?= true
BUILD_DSSI ?= false
BUILD_LADSPA ?= {{ "true" if cookiecutter.ui_type == "none" and
                             cookiecutter.want_midi_input == "no" and
                             cookiecutter.want_midi_output == "no"
                          else "false" }}

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
{% if cookiecutter.ui_type != "none" %}
UI_TYPE = {{ "cairo" if cookiecutter.ui_type == "cairo" else "opengl" }}
{%- endif %}
include ../../dpf/Makefile.plugins.mk

# --------------------------------------------------------------
# Enable all selected plugin types

ifeq ($(BUILD_LV2),true)
ifeq ($(HAVE_{{ "CAIRO" if cookiecutter.ui_type == "cairo" else "DGL" }}),true)
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
ifneq ($(MACOS_OR_WINDOWS),true)
ifeq ($(HAVE_{{ "CAIRO" if cookiecutter.ui_type == "cairo" else "DGL" }}),true)
ifeq ($(HAVE_LIBLO),true)
TARGETS += dssi
endif
endif
endif
endif

ifeq ($(BUILD_LADSPA),true)
TARGETS += ladspa
endif

all: $(TARGETS)

install: all
ifeq ($(BUILD_DSSI),true)
ifneq ($(MACOS_OR_WINDOWS),true)
ifeq ($(HAVE_{{ "CAIRO" if cookiecutter.ui_type == "cairo" else "DGL" }}),true)
ifeq ($(HAVE_LIBLO),true)
	@install -Dm755 $(TARGET_DIR)/$(NAME)-dssi$(LIB_EXT) -t $(DESTDIR)$(DSSI_DIR)
endif
endif
endif
endif
ifeq ($(BUILD_LADSPA),true)
	@install -Dm755 $(TARGET_DIR)/$(NAME)-ladspa$(LIB_EXT) -t $(DESTDIR)$(LADSPA_DIR)
endif
ifeq ($(BUILD_VST2),true)
	@install -Dm755 $(TARGET_DIR)/$(NAME)-vst$(LIB_EXT) -t $(DESTDIR)$(VST_DIR)
endif
ifeq ($(BUILD_LV2),true)
	@install -dm755 $(DESTDIR)$(LV2_DIR) && \
		cp -rpf $(TARGET_DIR)/$(NAME).lv2 $(DESTDIR)$(LV2_DIR)
endif
ifeq ($(BUILD_JACK),true)
ifeq ($(HAVE_JACK),true)
	@install -Dm755 $(TARGET_DIR)/$(NAME)$(APP_EXT) -t $(DESTDIR)$(BINDIR)
endif
endif

install-user: all
ifeq ($(BUILD_DSSI),true)
ifneq ($(MACOS_OR_WINDOWS),true)
ifeq ($(HAVE_{{ "CAIRO" if cookiecutter.ui_type == "cairo" else "DGL" }}),true)
ifeq ($(HAVE_LIBLO),true)
	@install -Dm755 $(TARGET_DIR)/$(NAME)-dssi$(LIB_EXT) -t $(USER_DSSI_DIR)
endif
endif
endif
endif
ifeq ($(BUILD_LADSPA),true)
	@install -Dm755 $(TARGET_DIR)/$(NAME)-ladspa$(LIB_EXT) -t $(USER_LADSPA_DIR)
endif
ifeq ($(BUILD_VST2),true)
	@install -Dm755 $(TARGET_DIR)/$(NAME)-vst$(LIB_EXT) -t $(USER_VST_DIR)
endif
ifeq ($(BUILD_LV2),true)
	@install -dm755 $(USER_LV2_DIR) && \
		cp -rpf $(TARGET_DIR)/$(NAME).lv2 $(USER_LV2_DIR)
endif
ifeq ($(BUILD_JACK),true)
ifeq ($(HAVE_JACK),true)
	@install -Dm755 $(TARGET_DIR)/$(NAME)$(APP_EXT) -t $(HOME)/bin
endif
endif

# --------------------------------------------------------------

.PHONY: all install install-user
