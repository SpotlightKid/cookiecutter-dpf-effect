#ifndef UI_{{ cookiecutter.plugin_name | upper }}_H
#define UI_{{ cookiecutter.plugin_name | upper }}_H

#include "DistrhoUI.hpp"

START_NAMESPACE_DISTRHO

class UI{{ cookiecutter.plugin_name }} : public UI {
public:
    UI{{ cookiecutter.plugin_name }}();
    ~UI{{ cookiecutter.plugin_name }}();

protected:
    void parameterChanged(uint32_t, float value) override;
    void programLoaded(uint32_t index) override;
    void sampleRateChanged(double newSampleRate) override;

    void uiIdle() override;
    void uiReshape(uint width, uint height) override;

    void onNanoDisplay() override;
    bool onKeyboard(const KeyboardEvent& ev) override;
    bool onSpecial(const SpecialEvent& ev) override;
    bool onMouse(const MouseEvent& ev) override;
    bool onMotion(const MotionEvent& ev) override;
    bool onScroll(const ScrollEvent& ev) override;

private:
    float    fParams[Plugin{{ cookiecutter.plugin_name }}::paramCount];
    double   fSampleRate;

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UI{{ cookiecutter.plugin_name }})
};

END_NAMESPACE_DISTRHO

#endif
