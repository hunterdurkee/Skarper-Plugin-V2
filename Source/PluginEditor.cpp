/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <cmath>

//==============================================================================
SkarperPluginV2AudioProcessorEditor::SkarperPluginV2AudioProcessorEditor(SkarperPluginV2AudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    setSize(400, 350);

    // Gain slider
    gainSlider.setSliderStyle(juce::Slider::LinearVertical);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 25);
    gainSlider.setRange(-10.0, 10.0, 0.1);
    gainSlider.setValue(0.0);
    gainSlider.setTextValueSuffix(" dB");
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);

    // Drive slider
    driveSlider.setSliderStyle(juce::Slider::LinearVertical);
    driveSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 25);
    driveSlider.setRange(1.0, 10.0, 0.1);
    driveSlider.setValue(1.0);
    driveSlider.addListener(this);
    addAndMakeVisible(driveSlider);
}

SkarperPluginV2AudioProcessorEditor::~SkarperPluginV2AudioProcessorEditor()
{}

//==============================================================================
void SkarperPluginV2AudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

    g.setColour(juce::Colours::white);
    g.setFont(juce::FontOptions(18.0f));

    g.drawFittedText("Skarper Plugin V2", 0, 10, 400, 30,
        juce::Justification::centred, 1);

    g.setFont(juce::FontOptions(14.0f));

    g.drawFittedText("Gain", 75, 45, 100, 25,
        juce::Justification::centred, 1);

    g.drawFittedText("Drive", 225, 45, 100, 25,
        juce::Justification::centred, 1);
}

void SkarperPluginV2AudioProcessorEditor::resized()
{
    gainSlider.setBounds(75, 70, 100, 250);
    driveSlider.setBounds(225, 70, 100, 250);
}

void SkarperPluginV2AudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &gainSlider)
    {
        audioProcessor.rawVolume =
            std::pow(10.0, gainSlider.getValue() / 20.0);
    }

    if (slider == &driveSlider)
    {
        audioProcessor.driveAmount = driveSlider.getValue();
    }
}