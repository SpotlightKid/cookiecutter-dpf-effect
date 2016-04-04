/*
 * {{ cookiecutter.project_name }} audio efffect based on DISTRHO Plugin Framework (DPF)
 * Copyright (C) {{ cookiecutter.year }} {{ cookiecutter.full_name }} <{{ cookiecutter.email }}>
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

#ifndef PLUGIN_{{ cookiecutter.plugin_name | upper }}_H
#define PLUGIN_{{ cookiecutter.plugin_name | upper }}_H

#include "DistrhoPlugin.hpp"

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------

class Plugin{{ cookiecutter.plugin_name }} : public Plugin {
public:
    enum Parameters {
        paramVolume = 0,
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
        return "{{ cookiecutter.project_license }}";
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
    // Process

    void activate() override;
    void run(const float**, float** outputs, uint32_t frames) override;

    // -------------------------------------------------------------------

private:
    float    fParams[paramCount];
    double   fSampleRate;

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Plugin{{ cookiecutter.plugin_name }})
};

// -----------------------------------------------------------------------

END_NAMESPACE_DISTRHO

#endif  // #ifndef PLUGIN_{{ cookiecutter.plugin_name | upper }}_H
