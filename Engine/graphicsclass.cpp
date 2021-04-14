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
	m_Position->SetPosition(0.0f, 0.0f, -10.0f);
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
	m_Light->SetDirection(0.0f, 0.0f, 1.0f);
	m_Light->SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->SetSpecularPower(64.0f);

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

	keyDown = m_Input->IsUpPressed();
	m_Position->MoveForward(keyDown);

	keyDown = m_Input->IsDownPressed();
	m_Position->MoveBackward(keyDown);

	keyDown = m_Input->IsAPressed();
	m_Position->MoveUpward(keyDown);

	keyDown = m_Input->IsZPressed();
	m_Position->MoveDownward(keyDown);

	keyDown = m_Input->IsPgUpPressed();
	m_Position->LookUpward(keyDown);

	keyDown = m_Input->IsPgDownPressed();
	m_Position->LookDownward(keyDown);

	// Get the view point position/rotation.
	m_Position->GetPosition(posX, posY, posZ);
	m_Position->GetRotation(rotX, rotY, rotZ);

	// Set the position of the camera.
	m_Camera->SetPosition(posX, posY, posZ);
	m_Camera->SetRotation(rotX, rotY, rotZ);

	return true;
}

bool GraphicsClass::Render()
{
	XMMATRIX worldMatrix, viewMatrix, projectionMatrix, translateMatrix, rotationMatrix;
	bool result;
	static float rotation = 0.0f;

	// Update the rotation variable each frame.
	rotation += (float)XM_PI * 0.0005f * m_Timer->GetTime();

	// Clear the buffers to begin the scene.
	m_D3D->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);

	// Generate the view matrix based on the camera's position.
	m_Camera->Render();

	// Get the world, view, and projection matrices from the camera and d3d objects.
	m_D3D->GetWorldMatrix(worldMatrix);
	m_Camera->GetViewMatrix(viewMatrix);
	m_D3D->GetProjectionMatrix(projectionMatrix);

	// Setup the rotation and translation of the first model Sun.

	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixRotationY(rotation));
	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixScaling(10.0f, 10.0f, 10.0f));
	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixTranslation(-10.5f, 0.0f, 0.0f));

	// Render the first model using the texture shader.
	m_Model1->Render(m_D3D->GetDeviceContext());
	result = m_ShaderManager->RenderLightShader(m_D3D->GetDeviceContext(), m_Model1->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model1->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	
	if(!result)
	{
		return false;
	}

	// Setup the rotation and translation of the second model Mercury.
	m_D3D->GetWorldMatrix(worldMatrix);

	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixRotationY(rotation));
	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixScaling(2.0f, 2.0f, 2.0f));
	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixTranslation(15.0f, 0.0f, 0.0f));

	// Render the second model using the light shader.
	m_Model2->Render(m_D3D->GetDeviceContext());
	result = m_ShaderManager->RenderLightShader(m_D3D->GetDeviceContext(), m_Model2->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, 
		m_Model2->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(), 
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if(!result)
	{
		return false;
	}

	// Setup the rotation and translation of the third model Venus.
	m_D3D->GetWorldMatrix(worldMatrix);

	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixRotationY(rotation));
	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixScaling(3.0f, 3.0f, 3.0f));
	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixTranslation(40.0f, 0.0f, 0.0f));

	// Render the third model using the bump map shader.
	m_Model3->Render(m_D3D->GetDeviceContext());
	result = m_ShaderManager->RenderLightShader(m_D3D->GetDeviceContext(), m_Model3->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model3->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if(!result)
	{
		return false;
	}

	// Setup the rotation and translation of the 4th model Earth.

	m_D3D->GetWorldMatrix(worldMatrix);

	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixRotationY(rotation));
	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixScaling(4.0f, 4.0f, 4.0f));
	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixTranslation(70.0f, 0.0f, 0.0f));

	// Render the forth model using the bump map shader.
	m_Model4->Render(m_D3D->GetDeviceContext());
	result = m_ShaderManager->RenderLightShader(m_D3D->GetDeviceContext(), m_Model4->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model4->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	// Setup the rotation and translation of the 5th model Mars.

	m_D3D->GetWorldMatrix(worldMatrix);

	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixRotationY(rotation));
	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixScaling(2.5f, 2.5f, 2.5f));
	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixTranslation(100.0f, 0.0f, 0.0f));

	// Render the fith model using the bump map shader.
	m_Model5->Render(m_D3D->GetDeviceContext());
	result = m_ShaderManager->RenderLightShader(m_D3D->GetDeviceContext(), m_Model5->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model5->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	// Setup the rotation and translation of the 6th model Jupiter.

	m_D3D->GetWorldMatrix(worldMatrix);

	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixRotationY(rotation));
	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixScaling(8.0f, 8.0f, 8.0f));
	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixTranslation(130.0f, 0.0f, 0.0f));

	// Render the sixth model using the bump map shader.
	m_Model6->Render(m_D3D->GetDeviceContext());
	result = m_ShaderManager->RenderLightShader(m_D3D->GetDeviceContext(), m_Model6->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model6->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}
	// Setup the rotation and translation of the 7th model Saturn.

	m_D3D->GetWorldMatrix(worldMatrix);

	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixRotationY(rotation));
	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixScaling(6.5f, 6.5f, 6.5f));
	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixTranslation(160.0f, 0.0f, 0.0f));

	// Render the seventh model using the bump map shader.
	m_Model7->Render(m_D3D->GetDeviceContext());
	result = m_ShaderManager->RenderLightShader(m_D3D->GetDeviceContext(), m_Model7->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model7->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}
	// Setup the rotation and translation of the 8th model Uranus.

	m_D3D->GetWorldMatrix(worldMatrix);

	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixRotationY(rotation));
	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixScaling(6.0f, 6.0f, 6.0f));
	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixTranslation(190.0f, 0.0f, 0.0f));

	// Render the eightth model using the bump map shader.
	m_Model8->Render(m_D3D->GetDeviceContext());
	result = m_ShaderManager->RenderLightShader(m_D3D->GetDeviceContext(), m_Model8->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model9->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	// Setup the rotation and translation of the 9th model Uranus.

	m_D3D->GetWorldMatrix(worldMatrix);

	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixRotationY(rotation));
	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixScaling(5.5f, 5.5f, 5.5f));
	worldMatrix = XMMatrixMultiply(worldMatrix, XMMatrixTranslation(220.0f, 0.0f, 0.0f));

	// Render the nineth model using the bump map shader.
	m_Model9->Render(m_D3D->GetDeviceContext());
	result = m_ShaderManager->RenderLightShader(m_D3D->GetDeviceContext(), m_Model9->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model9->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}


	//Floor/background render
	/*worldMatrix = XMMatrixIdentity();
	worldMatrix = XMMatrixScaling(10.0f, 3.0f, 10.0f);
	translateMatrix = XMMatrixTranslation(0.0f, -50.0f, 200.0f);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	// Render the first model using the texture shader.
	m_Model4->Render(m_D3D->GetDeviceContext());
	result = m_ShaderManager->RenderTextureShader(m_D3D->GetDeviceContext(), m_Model4->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model4->GetTexture());
	if (!result)
	{
		return false;
	}*/
	// Present the rendered scene to the screen.
	m_D3D->EndScene();


	return true;
}