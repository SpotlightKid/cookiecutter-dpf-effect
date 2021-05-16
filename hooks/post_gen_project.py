#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Init git repository and add DPF as a git submodule and make initial commit."""

from __future__ import print_function

from subprocess import call


submodule = "dpf"
submodule_url = "https://github.com/DISTRHO/DPF.git"
git_url = "git@github.com:{{ cookiecutter.github_username }}/{{ cookiecutter.repo_name }}"

print("\nRunning post-project-generation hook...\n")

print("Initializing new Git repository...")
call(['git', 'init'])
print("Adding '%s' as Git remote 'origin'." % git_url)
call(['git', 'remote', 'add', 'origin', git_url])
print("Adding Git submodule for DPF library:")
call(['git', 'submodule', 'add', submodule_url, submodule])
print("Making initial Git commit:")
call(['git', 'add', '-A'])
call(['git', 'commit', '-m', 'Initial commit'])

print("\nYour DPF audio effect plugin project is now ready!")
print("To compile it, change into the '{{ cookiecutter.repo_name }}' directory and type 'make'.")
print("The plugin binaries and LV2 bundle will be placed in the 'bin' subdirectory.")
print("Have fun!")
