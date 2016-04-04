cookiecutter-dpf-effect
=======================

A [cookiecutter] project template for DISTRHO Plugin Framework ([DPF]) audio
effect plugins.

To create a DPF effect plugin using this template, install cookiecutter (see
the [installation instructions]) and then run:

    cookiecutter https://github.com/SpotlightKid/cookiecutter-dpf-effect

and enter the plugin name and other info at the prompts.

A directory named after the value you gave for `repo_name` will be created
and initialized as a git repository and DPF added as a git submodule.

Enter the directory and run `make`:

    cd mynewplugin
    make

Plugin binaries will be placed in the `bin` directory. The source code for your
plugin is in a sub-directory of the `plugins` directory named after the value
you specified for `plugin_name`. Adapt it as you see fit and run `make` again
to update your binaries. The second compilation will be much faster, because
the DPF sources have already been built.


Requirements
------------

* Basic development tools (C++ compiler, make, etc.)
* Git
* [cookiecutter]


[cookiecutter]: https://github.com/audreyr/cookiecutter
[DPF]: https://github.com/DISTRHO/DPF
[installation instructions]: http://cookiecutter.readthedocs.org/en/latest/installation.html
