#!/usr/bin/make -f
# Makefile for DISTRHO Plugins #
# ---------------------------- #
# Created by falkTX, Christopher Arndt, and Patrick Desaulniers
#

include dpf/Makefile.base.mk

all: libs plugins gen

# --------------------------------------------------------------

submodules:
	git submodule update --init --recursive

libs:
{%- if cookiecutter.ui_type != "none" %}
	$(MAKE) -C dpf/dgl
{%- endif %}

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
gen: plugins dpf/utils/lv2_ttl_generator.exe
	@$(CURDIR)/dpf/utils/generate-ttl.sh

dpf/utils/lv2_ttl_generator.exe:
	$(MAKE) -C dpf/utils/lv2-ttl-generator WINDOWS=true
endif

# --------------------------------------------------------------

clean:
{%- if cookiecutter.ui_type != "none" %}
	$(MAKE) clean -C dpf/dgl
{%- endif %}
	$(MAKE) clean -C dpf/utils/lv2-ttl-generator
	$(MAKE) clean -C plugins/{{ cookiecutter.plugin_name }}
	rm -rf bin build

install: all
	$(MAKE) install -C plugins/{{ cookiecutter.plugin_name }}

install-user: all
	$(MAKE) install-user -C plugins/{{ cookiecutter.plugin_name }}

# --------------------------------------------------------------

.PHONY: all clean install install-user submodule libs plugins gen
