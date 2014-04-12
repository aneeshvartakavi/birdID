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
//[/Headers]

#include "MainComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainContentComponent::MainContentComponent ()
    : deviceManager(* new AudioDeviceManager()),thread ("Preview")
{
    addAndMakeVisible (audioThumbnail = new ThumbnailComponent (formatManager, transportSource, *zoomSlider));
    audioThumbnail->setName ("new component");

    addAndMakeVisible (label1 = new Label (String::empty,
                                           TRANS("BirdID\n")));
    label1->setFont (Font ("Candara", 22.00f, Font::plain));
    label1->setJustificationType (Justification::centred);
    label1->setEditable (false, false, false);
    label1->setColour (Label::backgroundColourId, Colour (0x00a6a6a6));
    label1->setColour (TextEditor::textColourId, Colours::black);
    label1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (startButton = new TextButton (String::empty));
    startButton->setButtonText (TRANS("Play/Stop"));
    startButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    startButton->addListener (this);
    startButton->setColour (TextButton::buttonColourId, Colours::black);
    startButton->setColour (TextButton::textColourOnId, Colours::white);
    startButton->setColour (TextButton::textColourOffId, Colour (0xffcdc9c9));

    addAndMakeVisible (zoomSlider = new Slider ("new slider"));
    zoomSlider->setRange (0, 10, 0);
    zoomSlider->setSliderStyle (Slider::LinearHorizontal);
    zoomSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    zoomSlider->setColour (Slider::thumbColourId, Colours::black);
    zoomSlider->addListener (this);

    addAndMakeVisible (zoomLabel = new Label ("new label",
                                              TRANS("Zoom")));
    zoomLabel->setFont (Font ("Candara", 20.50f, Font::plain));
    zoomLabel->setJustificationType (Justification::centredLeft);
    zoomLabel->setEditable (false, false, false);
    zoomLabel->setColour (TextEditor::textColourId, Colours::black);
    zoomLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (setupButton = new TextButton (String::empty));
    setupButton->setButtonText (TRANS("Audio Setup"));
    setupButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    setupButton->addListener (this);
    setupButton->setColour (TextButton::buttonColourId, Colours::black);
    setupButton->setColour (TextButton::textColourOnId, Colours::white);
    setupButton->setColour (TextButton::textColourOffId, Colour (0xffcdc9c9));

    addAndMakeVisible (processButton = new TextButton (String::empty));
    processButton->setButtonText (TRANS("Identify"));
    processButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    processButton->addListener (this);
    processButton->setColour (TextButton::buttonColourId, Colours::black);
    processButton->setColour (TextButton::textColourOnId, Colours::white);
    processButton->setColour (TextButton::textColourOffId, Colour (0xffcdc9c9));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (1024, 768);


    //[Constructor] You can add your own custom stuff here..
	deviceManager.initialise(2,2,nullptr,true);
	audioThumbnail->addChangeListener(this);
	thread.startThread (3);

	formatManager.registerBasicFormats();
	deviceManager.addAudioCallback (&audioSourcePlayer);
    audioSourcePlayer.setSource (&transportSource);
	birdID = new BirdID(1024,512);

	fileLoaded = false;
    //[/Constructor]
}

MainContentComponent::~MainContentComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    transportSource.setSource (nullptr);
    deviceManager.removeAudioCallback (&audioSourcePlayer);
	audioSourcePlayer.setSource (nullptr);
	audioThumbnail->removeChangeListener (this);
	zoomSlider->removeListener (this);
	audioSetup = nullptr;
	currentAudioFileSource = nullptr;
    //[/Destructor_pre]

    audioThumbnail = nullptr;
    label1 = nullptr;
    startButton = nullptr;
    zoomSlider = nullptr;
    zoomLabel = nullptr;
    setupButton = nullptr;
    processButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
	birdID = nullptr;

    //[/Destructor]
}

//==============================================================================
void MainContentComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff4a4a4a));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainContentComponent::resized()
{
    audioThumbnail->setBounds (48, 120, 920, 144);
    label1->setBounds (432, 64, 168, 40);
    startButton->setBounds (56, 280, 150, 24);
    zoomSlider->setBounds (864, 280, 96, 24);
    zoomLabel->setBounds (808, 280, 56, 24);
    setupButton->setBounds (64, 696, 150, 24);
    processButton->setBounds (432, 696, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainContentComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == startButton)
    {
        //[UserButtonCode_startButton] -- add your button handler code here..
         if (transportSource.isPlaying())
            {
                transportSource.stop();
            }
            else
            {
                transportSource.setPosition (0);
                transportSource.start();
            }
        //[/UserButtonCode_startButton]
    }
    else if (buttonThatWasClicked == setupButton)
    {
        //[UserButtonCode_setupButton] -- add your button handler code here..
		addAndMakeVisible(audioSetup = new AudioSetup(deviceManager));
        //[/UserButtonCode_setupButton]
    }
    else if (buttonThatWasClicked == processButton)
    {
        //[UserButtonCode_processButton] -- add your button handler code here..
        //[/UserButtonCode_processButton]
		if(fileLoaded)
		{
			if(birdID->runThread())
			{
				// Thread ran normally
			}
			else
			{
				// User requested cancel
			}


		}
		
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void MainContentComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == zoomSlider)
    {
        //[UserSliderCode_zoomSlider] -- add your slider handling code here..
		audioThumbnail->setZoomFactor (zoomSlider->getValue());
        //[/UserSliderCode_zoomSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void MainContentComponent::readDirectory()
{
	FileChooser fileChooser ("Select File to load...", File::getSpecialLocation (File::userHomeDirectory));
	if(fileChooser.browseForFileToOpen())
		{
			pathToFile = fileChooser.getResult();
		}
		else
		{
			pathToFile = File();
		}
}


void MainContentComponent::changeListenerCallback (ChangeBroadcaster* source)
{
    if (source == audioThumbnail)
        showFile (audioThumbnail->getLastDroppedFile());
}

void MainContentComponent::showFile (const File& file)
{
    loadFileIntoTransport (file);

    zoomSlider->setValue (0, dontSendNotification);
	audioThumbnail->setFile (file);
}

void MainContentComponent::loadFileIntoTransport (const File& audioFile)
{
    // unload the previous file source and delete it..
    transportSource.stop();
    transportSource.setSource (nullptr);
    currentAudioFileSource = nullptr;

    AudioFormatReader* reader = formatManager.createReaderFor (audioFile);

    if (reader != nullptr)
    {
        currentAudioFileSource = new AudioFormatReaderSource (reader, true);

        // ..and plug it into our transport source
        transportSource.setSource (currentAudioFileSource,
                                    32768,                   // tells it to buffer this many samples ahead
                                    &thread,                 // this is the background thread to use for reading-ahead
                                    reader->sampleRate);     // allows for sample rate correction
    
	birdID->selectFile(audioFile);
	fileLoaded = true;
	}

	
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainContentComponent" componentName=""
                 parentClasses="public Component, public ChangeListener" constructorParams=""
                 variableInitialisers="deviceManager(* new AudioDeviceManager()),thread (&quot;Preview&quot;)&#10;"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="1024" initialHeight="768">
  <BACKGROUND backgroundColour="ff4a4a4a"/>
  <GENERICCOMPONENT name="new component" id="7cb95d3164466318" memberName="audioThumbnail"
                    virtualName="" explicitFocusOrder="0" pos="48 120 920 144" class="ThumbnailComponent"
                    params="formatManager, transportSource, *zoomSlider"/>
  <LABEL name="" id="cd58986fe7eba495" memberName="label1" virtualName=""
         explicitFocusOrder="0" pos="432 64 168 40" bkgCol="a6a6a6" edTextCol="ff000000"
         edBkgCol="0" labelText="BirdID&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Candara"
         fontsize="22" bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="" id="380005bb9b91b092" memberName="startButton" virtualName=""
              explicitFocusOrder="0" pos="56 280 150 24" bgColOff="ff000000"
              textCol="ffffffff" textColOn="ffcdc9c9" buttonText="Play/Stop"
              connectedEdges="3" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="new slider" id="f61aebe640ae4d7a" memberName="zoomSlider"
          virtualName="" explicitFocusOrder="0" pos="864 280 96 24" thumbcol="ff000000"
          min="0" max="10" int="0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="8eaa9a342604a1de" memberName="zoomLabel"
         virtualName="" explicitFocusOrder="0" pos="808 280 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Zoom" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Candara" fontsize="20.5" bold="0"
         italic="0" justification="33"/>
  <TEXTBUTTON name="" id="ebe0a02516466f36" memberName="setupButton" virtualName=""
              explicitFocusOrder="0" pos="64 696 150 24" bgColOff="ff000000"
              textCol="ffffffff" textColOn="ffcdc9c9" buttonText="Audio Setup"
              connectedEdges="3" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="a5f342338127b12a" memberName="processButton" virtualName=""
              explicitFocusOrder="0" pos="432 696 150 24" bgColOff="ff000000"
              textCol="ffffffff" textColOn="ffcdc9c9" buttonText="Identify"
              connectedEdges="3" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
