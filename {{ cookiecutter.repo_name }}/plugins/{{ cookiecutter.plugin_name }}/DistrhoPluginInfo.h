/*
 * {{ cookiecutter.project_name }} audio effect based on DISTRHO Plugin Framework (DPF)
 *
 * SPDX-License-Identifier: {{ cookiecutter.project_license }}
 *
 * Copyright (C) {{ cookiecutter.year }} {{ cookiecutter.author_name }} <{{ cookiecutter.email }}>
{%- if cookiecutter.project_license == 'MIT' %}
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
{%- endif %}
 */

#ifndef DISTRHO_PLUGIN_INFO_H
#define DISTRHO_PLUGIN_INFO_H

// The plugin name.
// This is used to identify your plugin before a Plugin instance can be created.
#define DISTRHO_PLUGIN_NAME  "{{ cookiecutter.plugin_name }}"
// The plugin brand name. Used for the LV2 metadata and VST3 UI interface.
// Must be a valid C++ identifier, i.e. can not contain spaces or dashes.
#define DISTRHO_PLUGIN_BRAND "{{ cookiecutter.plugin_brand }}"
// The plugin URI when exporting in LV2 format.
// See https://lv2plug.in/book/#_manifest_ttl_in
#define DISTRHO_PLUGIN_URI   "{{ cookiecutter.plugin_uri }}"
// The plugin id when exporting in CLAP format, in reverse URI form
#define DISTRHO_PLUGIN_CLAP_ID "{{ cookiecutter.plugin_clap_id }}"

#define DISTRHO_PLUGIN_HAS_UI        {{ 0 if cookiecutter.ui_type == "none" else 1 }}
#define DISTRHO_UI_USE_NANOVG        {{ 1 if cookiecutter.ui_type == "nanovg" else 0 }}

#define DISTRHO_PLUGIN_IS_RT_SAFE       1
#define DISTRHO_PLUGIN_NUM_INPUTS       2
#define DISTRHO_PLUGIN_NUM_OUTPUTS      2
#define DISTRHO_PLUGIN_WANT_TIMEPOS     0
#define DISTRHO_PLUGIN_WANT_PROGRAMS    1
#define DISTRHO_PLUGIN_WANT_MIDI_INPUT  {{ 0 if cookiecutter.want_midi_input == "no" else 1 }}
#define DISTRHO_PLUGIN_WANT_MIDI_OUTPUT {{ 0 if cookiecutter.want_midi_output == "no" else 1 }}

// See http://lv2plug.in/ns/lv2core#ref-classes
#define DISTRHO_PLUGIN_LV2_CATEGORY "lv2:AmplifierPlugin"
// See https://github.com/DISTRHO/DPF/blob/1504e7d327bfe0eac6a889cecd199c963d35532f/distrho/DistrhoInfo.hpp#L717
#define DISTRHO_PLUGIN_VST3_CATEGORIES "Fx|Tools|Stereo"
// See https://github.com/DISTRHO/DPF/blob/1504e7d327bfe0eac6a889cecd199c963d35532f/distrho/DistrhoInfo.hpp#L761
#define DISTRHO_PLUGIN_CLAP_FEATURES "audio-effect", "utility", "stereo"

#endif // DISTRHO_PLUGIN_INFO_H
