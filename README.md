cookiecutter-dpf-effect
=======================

A [cookiecutter] project template for DISTRHO Plugin Framework ([DPF]) audio
effect plugins.

To create a DPF effect plugin using this template, install cookiecutter (see
the [installation instructions]) and then run:

    $ cookiecutter https://github.com/SpotlightKid/cookiecutter-dpf-effect

and enter the plugin name and other info at the prompts. See the
[cookiecutter documentation] on how to change the default values for these
prompts.

Here is an example:

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
    year [2018]:

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
     create mode 100644 Makefile.mk
     create mode 100644 README.md
     create mode 160000 dpf
     create mode 100644 plugins/Makefile.mk
     create mode 100644 plugins/SimpleGain/DistrhoPluginInfo.h
     create mode 100644 plugins/SimpleGain/Makefile
     create mode 100644 plugins/SimpleGain/PluginSimpleGain.cpp
     create mode 100644 plugins/SimpleGain/PluginSimpleGain.hpp

    Your DPF audio effect plugin project is now ready!
    To compile it, change into the 'simplegain' directory and type 'make'.
    The plugin binaries and LV2 bundle will be placed in the 'bin' subdirectory.
    Have fun!

A directory named after the value you gave for `repo_name` will be created
and initialized as a git repository and DPF added as a git submodule.

Enter the directory and run `make`:

    $ cd simplegain
    $ make

Plugin binaries will be placed in the `bin` sub-directory of your project. The
source code for your plugin is in a sub-directory of the `plugins` directory
named after the value you specified for `plugin_name`. Adapt it as you see fit
and run `make` again to update your binaries. The second compilation will be
much faster, because the DPF library has already been built.


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
