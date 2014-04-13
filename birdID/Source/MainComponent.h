/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_CB87035FA43504BB__
#define __JUCE_HEADER_CB87035FA43504BB__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "BirdID.h"
#include "ThumbnailComponent.h"
#include "AudioSetup.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
	An auto-generated component, created by the Introjucer.

	Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainContentComponent  : public Component,
                              public ChangeListener,
                              public ButtonListener,
                              public SliderListener
{
public:
    //==============================================================================
    MainContentComponent ();
    ~MainContentComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void readDirectory();
	void showFile (const File& file);
	void loadFileIntoTransport (const File& audioFile);
	void changeListenerCallback (ChangeBroadcaster* source) override;
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);
    void sliderValueChanged (Slider* sliderThatWasMoved);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	File pathToFile;
	ScopedPointer<BirdID> birdID;
	ScopedPointer<AudioFormatReaderSource> currentAudioFileSource;
	AudioSourcePlayer audioSourcePlayer;
    AudioTransportSource transportSource;
    AudioFormatManager formatManager;
	ScopedPointer<AudioDeviceManager> deviceManager;
	TimeSliceThread thread;

	ScopedPointer<AudioSetup> audioSetup;

	bool fileLoaded;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ThumbnailComponent> audioThumbnail;
    ScopedPointer<Label> label1;
    ScopedPointer<TextButton> startButton;
    ScopedPointer<Slider> zoomSlider;
    ScopedPointer<Label> zoomLabel;
    ScopedPointer<TextButton> setupButton;
    ScopedPointer<TextButton> processButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_CB87035FA43504BB__
