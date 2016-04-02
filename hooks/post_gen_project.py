#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Init git repository and add DPF as a git submodule."""

from subprocess import call

submodule = "dpf"
submodule_url = "git://github.com/DISTRHO/DPF.git"
git_url = "git@github.com:{{ cookiecutter.github_username }}/{{ cookiecutter.repo_name }}"

call(['git', 'init'])
call(['git', 'remote', 'add', 'origin', git_url])
call(['git', 'submodule', 'add', submodule_url, submodule])
