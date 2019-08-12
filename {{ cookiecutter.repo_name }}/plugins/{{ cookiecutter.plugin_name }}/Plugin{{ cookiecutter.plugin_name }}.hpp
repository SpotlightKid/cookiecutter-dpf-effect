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

#ifndef PLUGIN_{{ cookiecutter.plugin_name | upper }}_H
#define PLUGIN_{{ cookiecutter.plugin_name | upper }}_H

#include "DistrhoPlugin.hpp"

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------

class Plugin{{ cookiecutter.plugin_name }} : public Plugin {
public:
    enum Parameters {
        paramVolumeLeft = 0,
        paramVolumeRight,
        paramCount
    };

    Plugin{{ cookiecutter.plugin_name }}();

protected:
    // -------------------------------------------------------------------
    // Information

    const char* getLabel() const noexcept override {
        return "{{ cookiecutter.plugin_name }}";
    }

    const char* getDescription() const override {
        return "{{ cookiecutter.plugin_description }}";
    }

    const char* getMaker() const noexcept override {
        return "{{ cookiecutter.plugin_brand }}";
    }

    const char* getHomePage() const override {
        return "{{ cookiecutter.plugin_uri }}";
    }

    const char* getLicense() const noexcept override {
        return "https://spdx.org/licenses/{{ cookiecutter.project_license }}";
    }

    uint32_t getVersion() const noexcept override {
        return d_version({{ cookiecutter.version | replace('.', ', ') }});
    }

    // Go to:
    //
    // http://service.steinberg.de/databases/plugin.nsf/plugIn
    //
    // Get a proper plugin UID and fill it in here!
    int64_t getUniqueId() const noexcept override {
        return d_cconst('a', 'b', 'c', 'd');
    }

    // -------------------------------------------------------------------
    // Init

    void initParameter(uint32_t index, Parameter& parameter) override;
    void initProgramName(uint32_t index, String& programName) override;

    // -------------------------------------------------------------------
    // Internal data

    float getParameterValue(uint32_t index) const override;
    void setParameterValue(uint32_t index, float value) override;
    void loadProgram(uint32_t index) override;

    // -------------------------------------------------------------------
    // Optional

    // Optional callback to inform the plugin about a sample rate change.
    void sampleRateChanged(double newSampleRate) override;

    // -------------------------------------------------------------------
    // Process

    void activate() override;
{% if cookiecutter.want_midi_input == "no" %}
    void run(const float**, float** outputs, uint32_t frames) override;
{% else %}
    void run(const float**, float** outputs, uint32_t frames,
             const MidiEvent* midiEvents, uint32_t midiEventCount) override;
{% endif %}

    // -------------------------------------------------------------------

private:
    float    fParams[paramCount];
    double   fSampleRate;

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Plugin{{ cookiecutter.plugin_name }})
};

struct Preset {
    const char* name;
    float params[Plugin{{ cookiecutter.plugin_name }}::paramCount];
};

const Preset factoryPresets[] = {
    {
        "Default",
        {0.2f, 0.2f}
    }
    //,{
    //    "Another preset",  // preset name
    //    {0.5f, ...}        // array of presetCount float param values
    //}
};

const uint presetCount = sizeof(factoryPresets) / sizeof(Preset);

// -----------------------------------------------------------------------

END_NAMESPACE_DISTRHO

#endif  // #ifndef PLUGIN_{{ cookiecutter.plugin_name | upper }}_H
