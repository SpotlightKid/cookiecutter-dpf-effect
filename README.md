cookiecutter-dpf-effect
=======================

A [cookiecutter] project template for DISTRHO Plugin Framework ([DPF]) audio
effect plugins.

To create a DPF effect plugin using this template, install cookiecutter (see
the [installation instructions]) and then run:

```console
$ cookiecutter https://github.com/SpotlightKid/cookiecutter-dpf-effect
```

and enter the plugin name and other info at the prompts. See the
[cookiecutter documentation] on how to change the default values for these
prompts.

Here is an example:

```console
$ cookiecutter https://github.com/SpotlightKid/cookiecutter-dpf-effect
project_name [Simple Gain]:
plugin_description [A simple audio volume gain plugin]:
author_name [Joe Doe]: Christopher Arndt
domain [example.com]: chrisarndt.de
github_username [christopher.arndt]: SpotlightKid
email [SpotlightKid@chrisarndt.de]: info@chrisarndt.de
plugin_brand [chrisarndt.de]:
plugin_name [SimpleGain]:
repo_name [simplegain]:
plugin_uri [http://chrisarndt.de/plugins/simplegain]:
project_license [MIT]:
version [0.1.0]:
year [2019]:
Select ui_type:
1 - opengl
2 - nanovg
3 - cairo
4 - none
Choose from 1, 2, 3, 4 [1]: 4
Select want_midi_input:
1 - no
2 - yes
Choose from 1, 2 [1]: 1
Select want_midi_output:
1 - no
2 - yes
Choose from 1, 2 [1]: 1

Running post-project-generation hook...

Initializing new Git repository:
Initialized empty Git repository in /home/chris/simplegain/.git/
Adding Git submodule for DPF library:
Checking out submodules:
Cloning into '/home/chris/simplegain/dpf'...
remote: Counting objects: 7168, done.
remote: Total 7168 (delta 0), reused 0 (delta 0), pack-reused 7167
Receiving objects: 100% (7168/7168), 12.13 MiB | 1.30 MiB/s, done.
Resolving deltas: 100% (6078/6078), done.
Making initial Git commit:
[master (root-commit) dbdfbb6] Initial commit
 12 files changed, 699 insertions(+)
 create mode 100644 .gitignore
 create mode 100644 .gitmodules
 create mode 100644 LICENSE
 create mode 100644 Makefile
 create mode 100644 README.md
 create mode 160000 dpf
 create mode 100644 plugins/SimpleGain/DistrhoPluginInfo.h
 create mode 100644 plugins/SimpleGain/Makefile
 create mode 100644 plugins/SimpleGain/PluginSimpleGain.cpp
 create mode 100644 plugins/SimpleGain/PluginSimpleGain.hpp

Your DPF audio effect plugin project is now ready!
To compile it, change into the 'simplegain' directory and type 'make'.
The plugin binaries and LV2 bundle will be placed in the 'bin' subdirectory.
Have fun!
```

A directory named after the value you gave for `repo_name` will be created
and initialized as a git repository and DPF added as a git submodule.

Enter the directory and run `make`:

```console
$ cd simplegain
$ make
```

Plugin binaries will be placed in the `bin` sub-directory of your project. The
source code for your plugin is in a sub-directory of the `plugins` directory
named after the value you specified for `plugin_name`. Adapt it as you see fit
and run `make` again to update your binaries. The second compilation will be
much faster, because the DPF library has already been built.

To install the plugins system-wide, run `make install` (root priviledges may be
required). The usual `PREFIX` and `DESTDIR` makefile variables are honoured to
change the prefix directory (default: `/usr/local`) and the installation
destination (for distribution packaging).

Use make's `-n` option to see where the plugins would be installed without
actually installing them.

You can also set the installation directory for each plugin format with a
dedicated makefile variable.

* DSSI: `DSSI_DIR` (`<prefix>/lib/dssi`)
* LADSPA: `LADSPA_DIR` (`<prefix>/lib/ladspa`)
* LV2: `LV2_DIR` (`<prefix>/lib/lv2`)
* VST2: `VST_DIR` (`<prefix>/lib/vst`)
* Stand-alone JACK client program: `BINDIR` (`<prefix>/bin`)

Example: `make DESTDIR=/tmp/build-root VST_DIR=/usr/lib/lxvst install`

To install the plugins under your user's home directory, run `make install-user`.
No special makefile variables are used in this case.


Requirements
------------

* Basic development tools (C++ compiler, make, pkg-config, etc.)
* Python
* Git
* [cookiecutter]


[cookiecutter]: https://github.com/audreyr/cookiecutter
[cookiecutter documentation]: https://cookiecutter.readthedocs.io/en/0.9.1/advanced_usage.html#user-config-0-7-0
[DPF]: https://github.com/DISTRHO/DPF
[installation instructions]: http://cookiecutter.readthedocs.org/en/latest/installation.html


Authors
-------

* Christopher Arndt (@SpotlightKid), based on DPF examples by
* Filipe Coelho (@falkTX)
* Patrick Desaulniers (@pdesaulniers)
* Jean Pierre Cimalando (@jpcima)
