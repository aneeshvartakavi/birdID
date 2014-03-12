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
#include "FeatureExtractor.h"
//[/Headers]



//==============================================================================
/**
																	//[Comments]
	An auto-generated component, created by the Introjucer.

	Describe your class and how it works here!
																	//[/Comments]
*/
class MainContentComponent  : public Component,
							  public ButtonListener
{
public:
	//==============================================================================
	MainContentComponent ();
	~MainContentComponent();

	//==============================================================================
	//[UserMethods]     -- You can add your own custom methods in this section.
	void readDirectory();
	//[/UserMethods]

	void paint (Graphics& g);
	void resized();
	void buttonClicked (Button* buttonThatWasClicked);



private:
	//[UserVariables]   -- You can add your own custom variables in this section.
	File pathToFile;
	ScopedPointer<FeatureExtractor> featureExtractor;
	//[/UserVariables]

	//==============================================================================
	ScopedPointer<Label> label1;
	ScopedPointer<TextButton> browseButton;
	ScopedPointer<Label> browseLabel;


	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_CB87035FA43504BB__
