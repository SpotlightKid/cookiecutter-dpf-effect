#include "Plugin{{ cookiecutter.plugin_name }}.hpp"
#include "UI{{ cookiecutter.plugin_name }}.hpp"

START_NAMESPACE_DISTRHO

UI{{ cookiecutter.plugin_name }}::UI{{ cookiecutter.plugin_name }}()
: UI(600, 400)  {

}

UI{{ cookiecutter.plugin_name }}::~UI{{ cookiecutter.plugin_name }}() {

}

void UI{{ cookiecutter.plugin_name }}::parameterChanged(uint32_t index, float value) {
    fParams[index] = value;

    switch (index) {
        case Plugin{{ cookiecutter.plugin_name }}::paramVolume:
            // do something when volume param is set
            break;
    }
}

void UI{{ cookiecutter.plugin_name }}::programLoaded(uint32_t index) {
    switch (index) {
        case 0:
            setParameterValue(Plugin{{ cookiecutter.plugin_name }}::paramVolume, 0.1f);
            break;
    }
}

void UI{{ cookiecutter.plugin_name }}::sampleRateChanged(double newSampleRate) {
    fSampleRate = newSampleRate;
}

void UI{{ cookiecutter.plugin_name }}::uiIdle() {

}

void UI{{ cookiecutter.plugin_name }}::uiReshape(uint width, uint height) {
    (void)width;
    (void)height;
}

void UI{{ cookiecutter.plugin_name }}::onNanoDisplay() {

}

bool UI{{ cookiecutter.plugin_name }}::onKeyboard(const KeyboardEvent& ev) {
    return false;
    (void)ev;
}

bool UI{{ cookiecutter.plugin_name }}::onSpecial(const SpecialEvent& ev) {
    return false;
    (void)ev;
}

bool UI{{ cookiecutter.plugin_name }}::onMouse(const MouseEvent& ev) {
    return false;
    (void)ev;
}

bool UI{{ cookiecutter.plugin_name }}::onMotion(const MotionEvent& ev) {
    return false;
    (void)ev;
}

bool UI{{ cookiecutter.plugin_name }}::onScroll(const ScrollEvent& ev) {
    return false;
    (void)ev;
}

UI* createUI() {
    return new UI{{ cookiecutter.plugin_name }}();
}

END_NAMESPACE_DISTRHO
