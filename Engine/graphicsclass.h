////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _GRAPHICSCLASS_H_
#define _GRAPHICSCLASS_H_


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "inputclass.h"
#include "d3dclass.h"
#include "timerclass.h"
#include "shadermanagerclass.h"
#include "positionclass.h"
#include "cameraclass.h"
#include "lightclass.h"
#include "modelclass.h"
#include "bumpmodelclass.h"
#include "Skydomeclass.h"


/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = true;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;


////////////////////////////////////////////////////////////////////////////////
// Class name: GraphicsClass
////////////////////////////////////////////////////////////////////////////////
class GraphicsClass
{
public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	~GraphicsClass();

	bool Initialize(HINSTANCE, HWND, int, int);
	bool InitializePlanets(HINSTANCE, HWND, int, int);
	void Shutdown();
	bool Frame();
	bool RenderPlanets();

private:
	//bool Render(float);
	//Xu
	bool HandleMovementInput(float );
	bool Render();
	bool RenderPlanets(ModelClass* model, float scaleAmount, float translateValue, float orbitOffset, XMMATRIX worldMatrix, XMMATRIX viewMatrix, XMMATRIX projectionMatrix);
	bool RenderShips(ModelClass* model, float scaleAmount, float xValue, float yValue, float zValue, XMMATRIX worldMatrix, XMMATRIX viewMatrix, XMMATRIX projectionMatrix);
	float rotation = 0.0f;
	float orbitSpeed = 0.0f;
	bool stopOrbit = false;
	//bools for spawning planets once corresponding key is pressed
	bool onePress = false, twoPress = false, threePress = false, fourPress = false,
		fivePress = false, sixPress = false, sevenPress = false, eightPress = false, ninePress = false;

private:
	InputClass* m_Input;
	D3DClass* m_D3D;
	TimerClass* m_Timer;
	ShaderManagerClass* m_ShaderManager;
	PositionClass* m_Position;
	CameraClass* m_Camera;
	LightClass* m_Light;
	ModelClass* m_Model1;
	ModelClass* m_Model2;
	ModelClass* m_Model3;
	ModelClass* m_Model4;
	ModelClass* m_Model5;
	ModelClass* m_Model6;
	ModelClass* m_Model7;
	ModelClass* m_Model8;
	ModelClass* m_Model9;
	ModelClass* m_Model10;
	ModelClass* m_Model11;
	ModelClass* m_Model12;

	SkyDomeClass* m_SkyDome;
	
};

#endif