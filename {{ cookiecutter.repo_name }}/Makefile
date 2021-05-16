#!/usr/bin/make -f
# Makefile for DISTRHO Plugins #
# ---------------------------- #
# Created by falkTX, Christopher Arndt, and Patrick Desaulniers
#

ifeq ($(origin DPF_PATH), undefined)
    DPF_PATH ::= $(abspath ./dpf)
endif

export DPF_PATH

# error out if DPF is missing, unless the current rule is 'submodules'
define MISSING_SUBMODULES_ERROR
=============================================================================
DPF library not found (DPF_PATH = $(DPF_PATH)).
Please run "make submodules" to clone the missing Git submodules, then retry.
=============================================================================
endef

ifneq ($(MAKECMDGOALS), submodules)
ifeq (,$(wildcard $(DPF_PATH)/Makefile.base.mk))
    $(info $(MISSING_SUBMODULES_ERROR))
    $(error Unable to continue)
else
    include $(DPF_PATH)/Makefile.base.mk
endif
endif

# --------------------------------------------------------------
# Installation directories

PREFIX ?= /usr/local
BINDIR ?= $(PREFIX)/bin
LIBDIR ?= $(PREFIX)/lib
DSSI_DIR ?= $(LIBDIR)/dssi
LADSPA_DIR ?= $(LIBDIR)/ladspa
ifneq ($(MACOS_OR_WINDOWS),true)
LV2_DIR ?= $(LIBDIR)/lv2
VST2_DIR ?= $(LIBDIR)/vst
VST3_DIR ?= $(LIBDIR)/vst3
CLAP_DIR ?= $(LIBDIR)/clap
endif
ifeq ($(MACOS),true)
LV2_DIR ?= /Library/Audio/Plug-Ins/LV2
VST2_DIR ?= /Library/Audio/Plug-Ins/VST
VST3_DIR ?= /Library/Audio/Plug-Ins/VST3
CLAP_DIR ?= /Library/Audio/Plug-Ins/CLAP
endif
ifeq ($(WINDOWS),true)
LV2_DIR ?= $(COMMONPROGRAMFILES)/LV2
VST2_DIR ?= $(COMMONPROGRAMFILES)/VST2
VST3_DIR ?= $(COMMONPROGRAMFILES)/VST3
CLAP_DIR ?= $(COMMONPROGRAMFILES)/CLAP
endif

USER_DSSI_DIR ?= $(HOME)/.dssi
USER_LADSPA_DIR ?= $(HOME)/.ladspa
ifneq ($(MACOS_OR_WINDOWS),true)
USER_LV2_DIR ?= $(HOME)/.lv2
USER_VST2_DIR ?= $(HOME)/.vst
USER_VST3_DIR ?= $(HOME)/.vst3
USER_CLAP_DIR ?= $(HOME)/.clap
endif
ifeq ($(MACOS),true)
USER_LV2_DIR ?= $(HOME)/Library/Audio/Plug-Ins/LV2
USER_VST2_DIR ?= $(HOME)/Library/Audio/Plug-Ins/VST
USER_VST3_DIR ?= $(HOME)/Library/Audio/Plug-Ins/VST3
USER_CLAP_DIR ?= $(HOME)/Library/Audio/Plug-Ins/CLAP
endif
ifeq ($(WINDOWS),true)
USER_LV2_DIR ?= $(APPDATA)/LV2
USER_VST2_DIR ?= $(APPDATA)/VST
USER_VST3_DIR ?= $(APPDATA)/VST3
USER_CLAP_DIR ?= $(APPDATA)/CLAP
endif

export DESTDIR PREFIX BINDIR LIBDIR
export DSSI_DIR LADSPA_DIR LV2_DIR VST2_DIR VST3_DIR CLAP_DIR
export USER_DSSI_DIR USER_LADSPA_DIR USER_LV2_DIR USER_VST2_DIR USER_VST3_DIR USER_CLAP_DIR

# --------------------------------------------------------------
# Targets

all: libs plugins gen

# --------------------------------------------------------------

submodules:
	git submodule update --init --recursive

libs:
{%- if cookiecutter.ui_type != "none" %}
	$(MAKE) -C $(DPF_PATH)/dgl {{ "../build/libdgl-cairo.a" if cookiecutter.ui_type == "cairo" else "../build/libdgl-opengl.a" }}
{%- endif %}

plugins: libs
	$(MAKE) all -C plugins/{{ cookiecutter.plugin_name }}

ifneq ($(CROSS_COMPILING),true)
gen: plugins $(DPF_PATH)/utils/lv2_ttl_generator
	@$(DPF_PATH)/utils/generate-ttl.sh
ifeq ($(MACOS),true)
	@$(DPF_PATH)/utils/generate-vst-bundles.sh
endif

$(DPF_PATH)/utils/lv2_ttl_generator:
	$(MAKE) -C $(DPF_PATH)/utils/lv2-ttl-generator
else
gen: plugins $(DPF_PATH)/utils/lv2_ttl_generator.exe
	@$(DPF_PATH)/utils/generate-ttl.sh

$(DPF_PATH)/utils/lv2_ttl_generator.exe:
	$(MAKE) -C $(DPF_PATH)/utils/lv2-ttl-generator WINDOWS=true
endif

# --------------------------------------------------------------

clean:
{%- if cookiecutter.ui_type != "none" %}
	$(MAKE) clean -C $(DPF_PATH)/dgl
{%- endif %}
	$(MAKE) clean -C $(DPF_PATH)/utils/lv2-ttl-generator
	$(MAKE) clean -C plugins/{{ cookiecutter.plugin_name }}
	rm -rf bin build

install: all
	$(MAKE) install -C plugins/{{ cookiecutter.plugin_name }}

install-user: all
	$(MAKE) install-user -C plugins/{{ cookiecutter.plugin_name }}

# --------------------------------------------------------------

.PHONY: all clean install install-user submodules libs plugins gen
