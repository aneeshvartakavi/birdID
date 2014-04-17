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

//[Headers] You can add your own extra header files here...
#include "MainComponent.h"
//[/Headers]

#include "AudioSetup.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
AudioSetup::AudioSetup ():deviceManager(MainContentComponent::getSharedAudioDeviceManager())
{
    addAndMakeVisible (deviceSelector = new AudioDeviceSelectorComponent (deviceManager, 0, 2, 0, 2, true, true, true, false));

    addAndMakeVisible (backButton = new TextButton ("backButton"));
    backButton->setButtonText (TRANS("Back"));
    backButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    backButton->addListener (this);
    backButton->setColour (TextButton::buttonColourId, Colours::black);
    backButton->setColour (TextButton::textColourOnId, Colours::white);
    backButton->setColour (TextButton::textColourOffId, Colour (0xffcdc9c9));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (1024, 768);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

AudioSetup::~AudioSetup()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deviceSelector = nullptr;
    backButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void AudioSetup::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff4a4a4a));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void AudioSetup::resized()
{
    deviceSelector->setBounds (48, 72, getWidth() - 436, getHeight() - 350);
    backButton->setBounds (56, 704, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void AudioSetup::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == backButton)
    {
        //[UserButtonCode_backButton] -- add your button handler code here..
		setVisible(false);
        //[/UserButtonCode_backButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="AudioSetup" componentName=""
                 parentClasses="public Component" constructorParams="AudioDeviceManager&amp; deviceManager_"
                 variableInitialisers="deviceManager (deviceManager_)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="0"
                 initialWidth="1024" initialHeight="768">
  <BACKGROUND backgroundColour="ff4a4a4a"/>
  <GENERICCOMPONENT name="" id="a04c56de9f3fc537" memberName="deviceSelector" virtualName=""
                    explicitFocusOrder="0" pos="48 72 436M 350M" class="AudioDeviceSelectorComponent"
                    params="deviceManager, 0, 2, 0, 2, true, true, true, false"/>
  <TEXTBUTTON name="backButton" id="ebe0a02516466f36" memberName="backButton"
              virtualName="" explicitFocusOrder="0" pos="56 704 150 24" bgColOff="ff000000"
              textCol="ffffffff" textColOn="ffcdc9c9" buttonText="Back" connectedEdges="3"
              needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
