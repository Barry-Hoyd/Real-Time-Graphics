////////////////////////////////////////////////////////////////////////////////
// Filename: shadermanagerclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "shadermanagerclass.h"


ShaderManagerClass::ShaderManagerClass()
{
	m_TextureShader = 0;
	m_LightShader = 0;
	m_BumpMapShader = 0;
	m_SkyDomeShader = 0;
}


ShaderManagerClass::ShaderManagerClass(const ShaderManagerClass& other)
{
}


ShaderManagerClass::~ShaderManagerClass()
{
}


bool ShaderManagerClass::Initialize(ID3D11Device* device, HWND hwnd)
{
	bool result;

	

	// Create the texture shader object.
	m_TextureShader = new TextureShaderClass;
	if(!m_TextureShader)
	{
		return false;
	}

	// Initialize the texture shader object.
	result = m_TextureShader->Initialize(device, hwnd);
	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize the texture shader object.", L"Error", MB_OK);
		return false;
	}

	// Create the light shader object.
	m_LightShader = new LightShaderClass;
	if(!m_LightShader)
	{
		return false;
	}

	// Initialize the light shader object.
	result = m_LightShader->Initialize(device, hwnd);
	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize the light shader object.", L"Error", MB_OK);
		return false;
	}

	// Create the sky dome shader object.
	m_SkyDomeShader = new SkyDomeShaderClass;
	if (!m_SkyDomeShader)
	{
		return false;
	}

	// Initialize the sky dome shader object.
	result = m_SkyDomeShader->Initialize(device, hwnd);
	if (!result)
	{
		return false;
	}

	// Create the bump map shader object.
	m_BumpMapShader = new BumpMapShaderClass;
	if(!m_BumpMapShader)
	{
		return false;
	}

	// Initialize the bump map shader object.
	result = m_BumpMapShader->Initialize(device, hwnd);
	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize the bump map shader object.", L"Error", MB_OK);
		return false;
	}

	m_FireShader = new FireShaderClass;
	if (!m_FireShader)
	{
		return false;
	}
	result = m_FireShader->Initialize(device, hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the fire shader object.", L"Error", MB_OK);
		return false;
	}

	return true;
}


void ShaderManagerClass::Shutdown()
{
	// Release the bump map shader object.
	if(m_BumpMapShader)
	{
		m_BumpMapShader->Shutdown();
		delete m_BumpMapShader;
		m_BumpMapShader = 0;
	}

	// Release the sky dome shader object.
	if (m_SkyDomeShader)
	{
		m_SkyDomeShader->Shutdown();
		delete m_SkyDomeShader;
		m_SkyDomeShader = 0;
	}

	// Release the light shader object.
	if(m_LightShader)
	{
		m_LightShader->Shutdown();
		delete m_LightShader;
		m_LightShader = 0;
	}

	// Release the texture shader object.
	if(m_TextureShader)
	{
		m_TextureShader->Shutdown();
		delete m_TextureShader;
		m_TextureShader = 0;
	}

	return;
}


bool ShaderManagerClass::RenderTextureShader(ID3D11DeviceContext* device, int indexCount, const XMMATRIX &worldMatrix, const XMMATRIX &viewMatrix, const XMMATRIX &projectionMatrix,
											 ID3D11ShaderResourceView* texture)
{
	bool result;


	// Render the model using the texture shader.
	result = m_TextureShader->Render(device, indexCount, worldMatrix, viewMatrix, projectionMatrix, texture);
	if(!result)
	{
		return false;
	}

	return true;
}


bool ShaderManagerClass::RenderLightShader(ID3D11DeviceContext* deviceContext, int indexCount, const XMMATRIX &worldMatrix, const XMMATRIX &viewMatrix, const XMMATRIX &projectionMatrix,
	ID3D11ShaderResourceView* texture, XMFLOAT3 lightDirection, XMFLOAT4 ambient, XMFLOAT4 diffuse,
	XMFLOAT3 cameraPosition, XMFLOAT4 specular, float specularPower)
{
	bool result;


	// Render the model using the light shader.
	result = m_LightShader->Render(deviceContext, indexCount, worldMatrix, viewMatrix, projectionMatrix, texture, lightDirection, ambient, diffuse, cameraPosition, 
								   specular, specularPower);
	if(!result)
	{
		return false;
	}

	return true;
}


bool ShaderManagerClass::RenderBumpMapShader(ID3D11DeviceContext* deviceContext, int indexCount, const XMMATRIX &worldMatrix, const XMMATRIX &viewMatrix, const XMMATRIX &projectionMatrix,
	ID3D11ShaderResourceView* colorTexture, ID3D11ShaderResourceView* normalTexture, XMFLOAT3 lightDirection,
											 XMFLOAT4 diffuse)
{
	bool result;


	// Render the model using the bump map shader.
	result = m_BumpMapShader->Render(deviceContext, indexCount, worldMatrix, viewMatrix, projectionMatrix, colorTexture, normalTexture, lightDirection, diffuse);
	if(!result)
	{
		return false;
	}

	return true;
}

bool ShaderManagerClass::RenderSkyDomeShader(ID3D11DeviceContext* deviceContext, int indexCount, XMMATRIX worldMatrix, XMMATRIX viewMatrix,
	XMMATRIX projectionMatrix, XMFLOAT4 apexColor, XMFLOAT4 centerColor)
{
	return m_SkyDomeShader->Render(deviceContext, indexCount, worldMatrix, viewMatrix, projectionMatrix, apexColor, centerColor);
}

bool ShaderManagerClass::RenderFireShader(ID3D11DeviceContext* deviceContext, int indexCount, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix,
	const XMMATRIX& projectionMatrix, ID3D11ShaderResourceView* fireTexture,
	ID3D11ShaderResourceView* noiseTexture, ID3D11ShaderResourceView* alphaTexture, float frameTime,
	XMFLOAT3 scrollSpeeds, XMFLOAT3 scales, XMFLOAT2 distortion1, XMFLOAT2 distortion2,
	XMFLOAT2 distortion3, float distortionScale, float distortionBias)
{
	bool result;


	// Render the model using the fire shader.
	result = m_FireShader->Render(deviceContext, indexCount, worldMatrix, viewMatrix, projectionMatrix, fireTexture, noiseTexture, alphaTexture, frameTime, scrollSpeeds, scales, distortion1, distortion2,
		distortion3, distortionScale, distortionBias);

	if (!result)
	{
		return false;
	}

	return true;
}