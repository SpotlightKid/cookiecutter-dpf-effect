{% set dssi = False -%}
{% set ladspa = cookiecutter.ui_type == "none" and
                cookiecutter.want_midi_input == "no" and
                cookiecutter.want_midi_output == "no" -%}
# {{ cookiecutter.project_name }}

{{ cookiecutter.plugin_description }}

## Formats

All plugins in this collection come in the following plug-in formats:

{% if dssi -%}
* [DSSI]
{%- endif -%}
{% if ladspa -%}
* [LADSPA]
{%- endif -%}
* [LV2]
* [VST2]
* [VST3]
* [CLAP]

{% if cookiecutter.ui_type == "none" -%}
The plugins depend on the host to provide a generic UI to control parameters.
{% endif -%}


## Compiling

Make sure you have installed the required build tools and libraries (see
section "Prerequisites" below) and then clone this repository (including
sub-modules) and simply run `make` in the project's root directory:

```con
git clone --recursive https://github.com:{{ cookiecutter.github_username }}/{{ cookiecutter.repo_name }}
cd {{ cookiecutter.repo_name }}
make
```

## Installation

To install all plugin formats to their appropriate system-wide location, run
the following command (root priviledges may be required):

```con
make install
```

The makefiles support the usual `PREFIX` and `DESTDIR` variables to change the
installation prefix and set an installation root directory (defaulty: empty).
`PREFIX` defaults to `/usr/local`, but on macOS and Windows it is not used,
since the system-wide installation directories for plugins are fixed.

Use make's `-n` option to see where the plugins would be installed without
actually installing them.

You can also set the installation directory for each plugin format with a
dedicated makefile variable.

{% if dssi -%}
* DSSI: `DSSI_DIR` (`<prefix>/lib/dssi`)
{%- endif -%}
{% if ladspa -%}
* LADSPA: `LADSPA_DIR` (`<prefix>/lib/ladspa`)
{%- endif -%}
* LV2: `LV2_DIR` (`<prefix>/lib/lv2`)
* VST2: `VST2_DIR` (`<prefix>/lib/vst`)
* VST3: `VST3_DIR` (`<prefix>/lib/vst3`)
* CLAP: `CLAP_DIR` (`<prefix>/lib/clap`)

Example:

```con
make DESTDIR=/tmp/build-root PREFIX=/usr VST2_DIR=/usr/lib/lxvst install
```

To install the plugins only for your current user account, run:

```con
make install-user
```

Again, you can also set the installation directory for each plugin format with
a dedicated makefile variable.

{% if dssi -%}
* DSSI: `USER_DSSI_DIR` (`$HOME/.dssi`)
{%- endif -%}
{% if ladspa -%}
* LADSPA: `USER_LADSPA_DIR` (`$HOME/.ladspa`)
{%- endif -%}
* LV2: `USER_LV2_DIR` (`$HOME/.lv2`)
* VST2: `USER_VST2_DIR` (`$HOME/.vst`)
* VST3: `USER_VST3_DIR` (`$HOME/.vst3`)
* CLAP: `USER_CLAP_DIR` (`$HOME/.clap`)

*Note: The given default values for all of the above listed environment
variables differ depending on the target OS.*


## Prerequisites

* The GCC C++ compiler, library and the usual associated software build tools
  (GNU `make`, etc.).

  Debian / Ubuntu users should install the `build-essential` package
  to get these, Arch users the `base-devel` package group.

* [pkgconf]

The {% if dssi %}[DSSI], {% endif %}{% if ladspa %}[LADSPA], {% endif %}[LV2] and [VST2] (vestige) headers are included in the
[DPF] framework, which is integrated as a Git sub-module. These need not be
installed separately to build the software in the respective plug-in formats.


## Author

This software was created by *{{ cookiecutter.author_name }}*.


## Acknowledgements

This project is built using the DISTRHO Plugin Framework ([DPF]) and set up
with the [cookiecutter-dpf-effect] project template.


[cookiecutter-dpf-effect]: https://github.com/SpotlightKid/cookiecutter-dpf-effect
[DPF]: https://github.com/DISTRHO/DPF
{% if dssi -%}
[DSSI]: http://dssi.sourceforge.net/
{%- endif -%}
{% if ladspa -%}
[LADSPA]: http://www.ladspa.org/
{%- endif -%}
[LV2]: http://lv2plug.in/
[pkgconf]: https://github.com/pkgconf/pkgconf
[VST2/3]: https://en.wikipedia.org/wiki/Virtual_Studio_Technology
[CLAP]: https://cleveraudio.org/
