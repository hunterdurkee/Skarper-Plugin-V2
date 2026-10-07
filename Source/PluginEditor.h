/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class SkarperPluginV2AudioProcessorEditor : public juce::AudioProcessorEditor,
    public juce::Slider::Listener
{
public:
    SkarperPluginV2AudioProcessorEditor(SkarperPluginV2AudioProcessor&);
    ~SkarperPluginV2AudioProcessorEditor() override;

    //==============================================================================
    void paint(juce::Graphics&) override;
    void resized() override;

    void sliderValueChanged(juce::Slider* slider) override;

private:
    SkarperPluginV2AudioProcessor& audioProcessor;

    juce::Slider gainSlider;
    juce::Slider driveSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SkarperPluginV2AudioProcessorEditor)
};