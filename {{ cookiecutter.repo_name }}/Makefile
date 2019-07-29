#!/usr/bin/make -f
# Makefile for DISTRHO Plugins #
# ---------------------------- #
# Created by falkTX
#

include dpf/Makefile.base.mk

all: libs plugins gen

# --------------------------------------------------------------

define MISSING_SUBMODULES_ERROR

Could not find DPF. Please run "make submodules" to clone the missing submodules.

endef

# --------------------------------------------------------------

submodules: 
	git submodule update --init --recursive

libs:
ifeq (,$(wildcard dpf/dgl))
	$(error $(MISSING_SUBMODULES_ERROR))
{%- if cookiecutter.ui_type != "none" %}
else
	$(MAKE) -C dpf/dgl
{%- endif %}
endif

plugins: libs
	$(MAKE) all -C plugins/{{ cookiecutter.plugin_name }}

ifneq ($(CROSS_COMPILING),true)
gen: plugins dpf/utils/lv2_ttl_generator
	@$(CURDIR)/dpf/utils/generate-ttl.sh
ifeq ($(MACOS),true)
	@$(CURDIR)/dpf/utils/generate-vst-bundles.sh
endif

dpf/utils/lv2_ttl_generator:
	$(MAKE) -C dpf/utils/lv2-ttl-generator
else
gen:
endif

# --------------------------------------------------------------

clean:
{%- if cookiecutter.ui_type != "none" %}
	$(MAKE) clean -C dpf/dgl
{%- endif %}
	$(MAKE) clean -C dpf/utils/lv2-ttl-generator
	$(MAKE) clean -C plugins/{{ cookiecutter.plugin_name }}
	rm -rf bin build

# --------------------------------------------------------------

.PHONY: plugins
