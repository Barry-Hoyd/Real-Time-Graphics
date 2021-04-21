////////////////////////////////////////////////////////////////////////////////
// Filename: inputclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _INPUTCLASS_H_
#define _INPUTCLASS_H_


///////////////////////////////
// PRE-PROCESSING DIRECTIVES //
///////////////////////////////
#define DIRECTINPUT_VERSION 0x0800


/////////////
// LINKING //
/////////////
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")


//////////////
// INCLUDES //
//////////////
#include <dinput.h>


////////////////////////////////////////////////////////////////////////////////
// Class name: InputClass
////////////////////////////////////////////////////////////////////////////////
class InputClass
{
public:
	InputClass();
	InputClass(const InputClass&);
	~InputClass();

	bool Initialize(HINSTANCE, HWND, int, int);
	void Shutdown();
	bool Frame();

	void GetMouseLocation(int&, int&);


	void ResetCursorPos();
	int GetMouseX();
	int GetMouseY();
	int GetMouseXDelta();
	int GetMouseYDelta();

	/*Exit application*/
	bool IsEscapePressed();
	/*Rotation around Y Axis*/
	bool IsUpPressed();
	bool IsDownPressed();
	bool IsLeftPressed();
	bool IsRightPressed();
	/*Movement by WASD*/
	bool IsWPressed();
	bool IsSPressed();
	bool IsAPressed();
	bool IsDPressed();
	bool IsEPressed();
	bool IsQPressed();
	/*Stop planets orbiting*/
	bool IsSpacebarPressed();
	/*Spawn Planets*/
	bool Is1Pressed();
	bool Is2Pressed();
	bool Is3Pressed();
	bool Is4Pressed();
	bool Is5Pressed();
	bool Is6Pressed();
	bool Is7Pressed();
	bool Is8Pressed();
	bool Is9Pressed();

	/*Function controls*/
	bool IsF1Pressed();
	bool IsF2Pressed();
	bool IsF3Pressed();
	bool IsF4Pressed();

private:
	bool ReadKeyboard();
	bool ReadMouse();
	void ProcessInput();

private:
	IDirectInput8* m_directInput;
	IDirectInputDevice8* m_keyboard;
	IDirectInputDevice8* m_mouse;

	unsigned char m_keyboardState[256];
	DIMOUSESTATE m_mouseState;

	int m_screenWidth, m_screenHeight;
	int m_mouseX, m_mouseY, oldMouseX, oldMouseY;
};

#endif