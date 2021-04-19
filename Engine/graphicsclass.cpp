////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "graphicsclass.h"


GraphicsClass::GraphicsClass()
{
	m_Input = 0;
	m_D3D = 0;
	m_Timer = 0;
	m_ShaderManager = 0;
	m_Light = 0;
	m_Position = 0;
	m_Camera = 0;
	m_Model1 = 0;
	m_Model2 = 0;
	m_Model3 = 0;
	//Initialised, will be my iceland model. 28/11/2019
	m_Model4 = 0;
}


GraphicsClass::GraphicsClass(const GraphicsClass& other)
{
}


GraphicsClass::~GraphicsClass()
{
}


bool GraphicsClass::Initialize(HINSTANCE hinstance, HWND hwnd, int screenWidth, int screenHeight)
{
	bool result;

	// Create the input object.  The input object will be used to handle reading the keyboard and mouse input from the user.
	m_Input = new InputClass;
	if (!m_Input)
	{
		return false;
	}

	// Initialize the input object.
	result = m_Input->Initialize(hinstance, hwnd, screenWidth, screenHeight);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the input object.", L"Error", MB_OK);
		return false;
	}

	// Create the Direct3D object.
	m_D3D = new D3DClass;
	if(!m_D3D)
	{
		return false;
	}

	// Initialize the Direct3D object.
	result = m_D3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize Direct3D.", L"Error", MB_OK);
		return false;
	}

	// Create the shader manager object.
	m_ShaderManager = new ShaderManagerClass;
	if(!m_ShaderManager)
	{
		return false;
	}

	// Initialize the shader manager object.
	result = m_ShaderManager->Initialize(m_D3D->GetDevice(), hwnd);
	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize the shader manager object.", L"Error", MB_OK);
		return false;
	}

	// Create the timer object.
	m_Timer = new TimerClass;
	if (!m_Timer)
	{
		return false;
	}

	// Initialize the timer object.
	result = m_Timer->Initialize();
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the timer object.", L"Error", MB_OK);
		return false;
	}

	// Create the position object.
	m_Position = new PositionClass;
	if (!m_Position)
	{
		return false;
	}

	// Set the initial position and rotation of the viewer.
	m_Position->SetPosition(0.0f, 0.0f, -40.0f);
	m_Position->SetRotation(0.0f, 0.0f, 0.0f);

	// Create the camera object.
	m_Camera = new CameraClass;
	if(!m_Camera)
	{
		return false;
	}

	// Set the initial position of the camera.
	//m_Camera->SetPosition(0.0f, 0.0f, -10.0f);

	// Create the light object.
	m_Light = new LightClass;
	if(!m_Light)
	{
		return false;
	}

	// Initialize the light object.
    m_Light->SetAmbientColor(0.15f, 0.15f, 0.15f, 1.0f);
	m_Light->SetDiffuseColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->SetDirection(0.0f, 0.0f, 20.0f);
	m_Light->SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->SetSpecularPower(128.0f);

	// Create the model object.
	m_Model1 = new ModelClass;
	if(!m_Model1)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model1->Initialize(m_D3D->GetDevice(), "../Engine/data/sphere1.txt", L"../Engine/data/sun.dds");
	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize the first model object.", L"Error", MB_OK);
		return false;
	}

	// Create the second model object.
	m_Model2 = new ModelClass;
	if(!m_Model2)
	{
		return false;
	}

	// Initialize the second model object.
	result = m_Model2->Initialize(m_D3D->GetDevice(), "../Engine/data/sphere1.txt", L"../Engine/data/mercury.dds");
	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize the second model object.", L"Error", MB_OK);
		return false;
	}

	// Create the third bump model object for models with normal maps and related vectors.
	m_Model3 = new ModelClass;
	if(!m_Model3)
	{
		return false;
	}

	// Initialize the bump model object.
	result = m_Model3->Initialize(m_D3D->GetDevice(), "../Engine/data/sphere1.txt", L"../Engine/data/venus.dds");
	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize the third model object.", L"Error", MB_OK);
		return false;
	}

	// Create the 4th model object.
	m_Model4 = new ModelClass;
	if (!m_Model4)
	{
		return false;
	}

	// Initialize the 4th model object.
	result = m_Model4->Initialize(m_D3D->GetDevice(), "../Engine/data/sphere1.txt", L"../Engine/data/earth.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the 4th model object.", L"Error", MB_OK);
		return false;
	}

	// Create the 5th model object.
	m_Model5 = new ModelClass;
	if (!m_Model5)
	{
		return false;
	}

	// Initialize the 5th model object.
	result = m_Model5->Initialize(m_D3D->GetDevice(), "../Engine/data/sphere1.txt", L"../Engine/data/mars.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the 5th model object.", L"Error", MB_OK);
		return false;
	}

	// Create the 6th model object.
	m_Model6 = new ModelClass;
	if (!m_Model6)
	{
		return false;
	}

	// Initialize the 6th model object.
	result = m_Model6->Initialize(m_D3D->GetDevice(), "../Engine/data/sphere1.txt", L"../Engine/data/jupiter.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the 5th model object.", L"Error", MB_OK);
		return false;
	}

	// Create the 7th model object.
	m_Model7 = new ModelClass;
	if (!m_Model7)
	{
		return false;
	}

	// Initialize the 7th model object.
	result = m_Model7->Initialize(m_D3D->GetDevice(), "../Engine/data/sphere1.txt", L"../Engine/data/saturn.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the 5th model object.", L"Error", MB_OK);
		return false;
	}

	// Create the 8th model object.
	m_Model8 = new ModelClass;
	if (!m_Model8)
	{
		return false;
	}

	// Initialize the 8th model object.
	result = m_Model8->Initialize(m_D3D->GetDevice(), "../Engine/data/sphere1.txt", L"../Engine/data/uranus.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the 5th model object.", L"Error", MB_OK);
		return false;
	}

	// Create the 9th model object.
	m_Model9 = new ModelClass;
	if (!m_Model9)
	{
		return false;
	}

	// Initialize the 9th model object.
	result = m_Model9->Initialize(m_D3D->GetDevice(), "../Engine/data/sphere1.txt", L"../Engine/data/neptune.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the 5th model object.", L"Error", MB_OK);
		return false;
	}

	// Create the 10th model object.
	m_Model10 = new ModelClass;
	if (!m_Model10)
	{
		return false;
	}

	// Initialize the 10th model object.
	result = m_Model10->Initialize(m_D3D->GetDevice(), "../Engine/data/ring.txt", L"../Engine/data/ring1.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the 10th model object.", L"Error", MB_OK);
		return false;
	}

	// Create the 11th model object.
	m_Model11 = new ModelClass;
	if (!m_Model11)
	{
		return false;
	}
	// Initialize the 11th model object.
	result = m_Model11->Initialize(m_D3D->GetDevice(), "../Engine/data/Iceland.txt", L"../Engine/data/milkyWay.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the 11th model object.", L"Error", MB_OK);
		return false;
	}

	// Create the 12th model object.
	m_Model12 = new ModelClass;
	if (!m_Model12)
	{
		return false;
	}
	// Initialize the 11th model object.
	result = m_Model12->Initialize(m_D3D->GetDevice(), "../Engine/data/spaceship.txt", L"../Engine/data/metal.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the 12th model object.", L"Error", MB_OK);
		return false;
	}
	return true;
}

void GraphicsClass::Shutdown()
{
	// Release the model objects.
	if(m_Model1)
	{
		m_Model1->Shutdown();
		delete m_Model1;
		m_Model1 = 0;
	}

	if(m_Model2)
	{
		m_Model2->Shutdown();
		delete m_Model2;
		m_Model2 = 0;
	}

	if(m_Model3)
	{
		m_Model3->Shutdown();
		delete m_Model3;
		m_Model3 = 0;
	}

	if (m_Model4)
	{
		m_Model4->Shutdown();
		delete m_Model4;
		m_Model4 = 0;
	}

	// Release the light object.
	if(m_Light)
	{
		delete m_Light;
		m_Light = 0;
	}

	// Release the camera object.
	if(m_Camera)
	{
		delete m_Camera;
		m_Camera = 0;
	}

	// Release the position object.
	if (m_Position)
	{
		delete m_Position;
		m_Position = 0;
	}

	// Release the shader manager object.
	if(m_ShaderManager)
	{
		m_ShaderManager->Shutdown();
		delete m_ShaderManager;
		m_ShaderManager = 0;
	}

	// Release the timer object.
	if (m_Timer)
	{
		delete m_Timer;
		m_Timer = 0;
	}

	// Release the D3D object.
	if(m_D3D)
	{
		m_D3D->Shutdown();
		delete m_D3D;
		m_D3D = 0;
	}

	// Release the input object.
	if (m_Input)
	{
		m_Input->Shutdown();
		delete m_Input;
		m_Input = 0;
	}

	return;
}

bool GraphicsClass::Frame()
{
	bool result;
	static float rotation = 0.0f;


	// Update the rotation variable each frame.
	rotation += (float)XM_PI * 0.005f;
	if (rotation > 360.0f)
	{
		rotation -= 360.0f;
	}

	
	// Update the system stats.
	m_Timer->Frame();

	// Read the user input.
	result = m_Input->Frame();
	if (!result)
	{
		return false;
	}

	// Check if the user pressed escape and wants to exit the application.
	if (m_Input->IsEscapePressed() == true)
	{
		return false;
	}

	// Do the frame input processing.
	result = HandleMovementInput(m_Timer->GetTime());
	if (!result)
	{
		return false;
	}

	// Render the graphics.
	// Render the graphics scene.
	result = Render();
	if (!result)
	{
		return false;
	}

	return true;
}

bool GraphicsClass::HandleMovementInput(float frameTime)
{
	bool keyDown;
	float posX, posY, posZ, rotX, rotY, rotZ;

	// Set the frame time for calculating the updated position.
	m_Position->SetFrameTime(frameTime);

	// Handle the input.
	keyDown = m_Input->IsLeftPressed();
	m_Position->TurnLeft(keyDown);

	keyDown = m_Input->IsRightPressed();
	m_Position->TurnRight(keyDown);

	keyDown = m_Input->IsWPressed();
	m_Position->MoveForward(keyDown);

	keyDown = m_Input->IsSPressed();
	m_Position->MoveBackward(keyDown);

	keyDown = m_Input->IsAPressed();
	m_Position->MoveLeft(keyDown);

	keyDown = m_Input->IsDPressed();
	m_Position->MoveRight(keyDown);

	keyDown = m_Input->IsEPressed();
	m_Position->MoveUpward(keyDown);

	keyDown = m_Input->IsQPressed();
	m_Position->MoveDownward(keyDown);

	keyDown = m_Input->IsUpPressed();
	m_Position->LookUpward(keyDown);

	keyDown = m_Input->IsDownPressed();
	m_Position->LookDownward(keyDown);

	if (m_Input->Is1Pressed())
	{
		onePress = true;
	}

	if (m_Input->Is2Pressed())
	{
		twoPress = true;
	}

	if (m_Input->Is3Pressed())
	{
		threePress = true;
	}

	if (m_Input->Is4Pressed())
	{
		fourPress = true;
	}

	if (m_Input->Is5Pressed())
	{
		fivePress = true;
	}

	if (m_Input->Is6Pressed())
	{
		sixPress = true;
	}

	if (m_Input->Is7Pressed())
	{
		sevenPress = true;
	}

	if (m_Input->Is8Pressed())
	{
		eightPress = true;
	}
	
	if (m_Input->Is9Pressed())
	{
		ninePress = true;
	}
	
	if (m_Input->IsSpacebarPressed())
	{
		stopOrbit = true;
	}
	else
	{
		stopOrbit = false;
	}
	//*/
	// HandleMouse Rotations
	m_Position->MouseRotate(m_Input->GetMouseXDelta(), m_Input->GetMouseYDelta());

	// Get the view point position/rotation.
	m_Position->GetPosition(posX, posY, posZ);
	m_Position->GetRotation(rotX, rotY, rotZ);
	m_Input->ResetCursorPos();

	// Set the position of the camera.
	m_Camera->SetPosition(posX, posY, posZ);
	m_Camera->SetRotation(rotX, rotY, rotZ);

	return true;
}

bool GraphicsClass::Render()
{
	XMMATRIX worldMatrix, viewMatrix, projectionMatrix, translateMatrix;
	XMMATRIX scale;
	XMVECTOR MyAxis;
	bool result;
	
	if (!stopOrbit)
	{
		// Update the rotation variable each frame.
		orbitSpeed += (float)XM_PI * 0.0005f * m_Timer->GetTime();
	}
	rotation += (float)XM_PI * 0.0005f * m_Timer->GetTime();

	// Clear the buffers to begin the scene.
	m_D3D->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);

	// Generate the view matrix based on the camera's position.
	m_Camera->Render();

	// Get the world, view, and projection matrices from the camera and d3d objects.
	m_D3D->GetWorldMatrix(worldMatrix);
	m_Camera->GetViewMatrix(viewMatrix);
	m_D3D->GetProjectionMatrix(projectionMatrix);

	// Setup the rotation and translation of the 1st model Sun.
	if (onePress)
	{
		RenderPlanets(m_Model1, 10.0f, 0.0f, worldMatrix, viewMatrix, projectionMatrix);
	}
	
	// Setup the rotation and translation of the 2nd model Mercury.
	if (twoPress)
	{
		RenderPlanets(m_Model2, 2.0f, 30.0f, worldMatrix, viewMatrix, projectionMatrix);
	}
	

	// Setup the rotation and translation of the 3rd model Venus.
	if (threePress)
	{
		RenderPlanets(m_Model3, 2.5f, 60.0f, worldMatrix, viewMatrix, projectionMatrix);
	}
	
	// Setup the rotation and translation of the 4th model Earth.
	if (fourPress)
	{
		RenderPlanets(m_Model4, 3.0f, 90.0f, worldMatrix, viewMatrix, projectionMatrix);
	}
	
	// Setup the rotation and translation of the 5th model Mars.
	if (fivePress)
	{
		RenderPlanets(m_Model5, 2.25f, 120.0f, worldMatrix, viewMatrix, projectionMatrix);
	}
	

	// Setup the rotation and translation of the 6th model Jupiter.
	if (sixPress)
	{
		RenderPlanets(m_Model6, 8.0f, 150.0f, worldMatrix, viewMatrix, projectionMatrix);
	}
	

	// Setup the rotation and translation of the 7th model Saturn.
	if (sevenPress)
	{
		RenderPlanets(m_Model7, 7.0f, 180.0f, worldMatrix, viewMatrix, projectionMatrix);
		
		RenderPlanets(m_Model10, 7.50f, 180.0f, worldMatrix, viewMatrix, projectionMatrix);
	}
	

	// Setup the rotation and translation of the 8th model Uranus.
	if (eightPress)
	{
		RenderPlanets(m_Model8, 6.0f, 210.0f, worldMatrix, viewMatrix, projectionMatrix);
	}
	

	// Setup the rotation and translation of the 9th model Neptune.
	if (ninePress)
	{
		RenderPlanets(m_Model9, 5.0f, 240.0f, worldMatrix, viewMatrix, projectionMatrix);
	}

	// Setup the rotation and translation of the 11thth model Milkyway.
	worldMatrix = XMMatrixIdentity();
	worldMatrix = XMMatrixScaling(10.0f, 3.0f, 10.0f);
	translateMatrix = XMMatrixTranslation(0.0f, -50.0f, 200.0f);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	// Render the first model using the texture shader.
	m_Model11->Render(m_D3D->GetDeviceContext());
	result = m_ShaderManager->RenderTextureShader(m_D3D->GetDeviceContext(), m_Model11->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model11->GetTexture());
	if (!result)
	{
		return false;
	}

	// Setup the rotation and translation of the 12th model Spaceship.
	bool movingForward = true;
	m_D3D->GetWorldMatrix(worldMatrix);
	scale = XMMatrixScaling(1.0f, 1.0f, 1.0f);
	worldMatrix = XMMatrixMultiply(worldMatrix, scale);
	
	translateMatrix = XMMatrixTranslation(0.0f + cos(timeGetTime() / 500.0f) * 50, 0.0f + cos(timeGetTime() / 500.0f) * 10, 200.0f);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);
	//worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixRotationY(rotation));
	// Render the 9th model using the light shader.
	m_Model12->Render(m_D3D->GetDeviceContext());
	result = m_ShaderManager->RenderLightShader(m_D3D->GetDeviceContext(), m_Model12->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model12->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}
	// Present the rendered scene to the screen.
	m_D3D->EndScene();

	return true;
}

bool GraphicsClass::RenderPlanets(ModelClass* model, float scaleAmount, float translateValue, XMMATRIX worldMatrix, XMMATRIX viewMatrix, XMMATRIX projectionMatrix)
{
	bool result;
	XMMATRIX scale, translateMatrix;
	XMVECTOR MyAxis;

	m_D3D->GetWorldMatrix(worldMatrix);
	scale = XMMatrixScaling(scaleAmount,scaleAmount,scaleAmount);
	worldMatrix = XMMatrixMultiply(worldMatrix, scale);
	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixRotationY(rotation));
	translateMatrix = XMMatrixTranslation(translateValue,0.0f,0.0f);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);
	MyAxis = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixRotationAxis(MyAxis, orbitSpeed));

	// Render the 2nd model using the light shader.
	model->Render(m_D3D->GetDeviceContext());
	result = m_ShaderManager->RenderLightShader(m_D3D->GetDeviceContext(), model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		model->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	return true;
}
