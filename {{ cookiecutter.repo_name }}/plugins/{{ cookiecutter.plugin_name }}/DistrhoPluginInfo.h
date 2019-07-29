/*
 * {{ cookiecutter.project_name }} audio effect based on DISTRHO Plugin Framework (DPF)
 * Copyright (C) {{ cookiecutter.year }} {{ cookiecutter.author_name }} <{{ cookiecutter.email }}>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef DISTRHO_PLUGIN_INFO_H
#define DISTRHO_PLUGIN_INFO_H

#define DISTRHO_PLUGIN_BRAND "{{ cookiecutter.plugin_brand }}"
#define DISTRHO_PLUGIN_NAME  "{{ cookiecutter.plugin_name }}"
#define DISTRHO_PLUGIN_URI   "{{ cookiecutter.plugin_uri }}"

#define DISTRHO_PLUGIN_HAS_UI        {{ 0 if cookiecutter.ui_type == "none" else 1 }}
#define DISTRHO_UI_USE_NANOVG        {{ 1 if cookiecutter.ui_type == "nanovg" else 0 }}

#define DISTRHO_PLUGIN_IS_RT_SAFE    1
#define DISTRHO_PLUGIN_NUM_INPUTS    2
#define DISTRHO_PLUGIN_NUM_OUTPUTS   2
#define DISTRHO_PLUGIN_WANT_TIMEPOS  0
#define DISTRHO_PLUGIN_WANT_PROGRAMS 1

#endif // DISTRHO_PLUGIN_INFO_H
