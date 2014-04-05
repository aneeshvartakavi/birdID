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
{
    addAndMakeVisible (label1 = new Label (String::empty,
                                           TRANS("BirdID\n")));
    label1->setFont (Font (22.00f, Font::plain));
    label1->setJustificationType (Justification::centredLeft);
    label1->setEditable (false, false, false);
    label1->setColour (TextEditor::textColourId, Colours::black);
    label1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (browseButton = new TextButton (String::empty));
    browseButton->setButtonText (TRANS("Browse"));
    browseButton->addListener (this);

    addAndMakeVisible (browseLabel = new Label (String::empty,
                                                TRANS("Browse local hard drive for files")));
    browseLabel->setFont (Font (15.00f, Font::plain));
    browseLabel->setJustificationType (Justification::centredLeft);
    browseLabel->setEditable (false, false, false);
    browseLabel->setColour (TextEditor::textColourId, Colours::black);
    browseLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
	birdID = new BirdID(1024,512);
	//featureExtractor = new FeatureExtractor();
    //[/Constructor]
}

MainContentComponent::~MainContentComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label1 = nullptr;
    browseButton = nullptr;
    browseLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
	birdID = nullptr;
	//[/Destructor]
}

//==============================================================================
void MainContentComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainContentComponent::resized()
{
    label1->setBounds (120, 32, 168, 40);
    browseButton->setBounds (112, 160, 150, 24);
    browseLabel->setBounds (120, 96, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainContentComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == browseButton)
    {
        //[UserButtonCode_browseButton] -- add your button handler code here..
		readDirectory();
		//birdID->readAudioFile(pathToFile);
		birdID->process(pathToFile);
		//		featureExtractor->computeFeatures(pathToFile);
        //[/UserButtonCode_browseButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
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
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainContentComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <LABEL name="" id="cd58986fe7eba495" memberName="label1" virtualName=""
         explicitFocusOrder="0" pos="120 32 168 40" edTextCol="ff000000"
         edBkgCol="0" labelText="BirdID&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="22" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="" id="380005bb9b91b092" memberName="browseButton" virtualName=""
              explicitFocusOrder="0" pos="112 160 150 24" buttonText="Browse"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="" id="d81d55e5c30d5bb1" memberName="browseLabel" virtualName=""
         explicitFocusOrder="0" pos="120 96 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Browse local hard drive for files" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
