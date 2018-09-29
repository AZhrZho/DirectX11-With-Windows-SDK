#ifndef MODEL_H
#define MODEL_H

#include <DDSTextureLoader.h>
#include <WICTextureLoader.h>
#include "Effects.h"
#include "ObjReader.h"
#include "Geometry.h"

struct ModelPart
{
	// ʹ��ģ�����(C++11)��������
	template <class T>
	using ComPtr = Microsoft::WRL::ComPtr<T>;

	Material material;
	ComPtr<ID3D11ShaderResourceView> texA;
	ComPtr<ID3D11ShaderResourceView> texD;
	ComPtr<ID3D11Buffer> vertexBuffer;
	ComPtr<ID3D11Buffer> indexBuffer;
	UINT vertexCount;
	UINT indexCount;
	DXGI_FORMAT indexFormat;
};

struct Model
{
	// ʹ��ģ�����(C++11)��������
	template <class T>
	using ComPtr = Microsoft::WRL::ComPtr<T>;
	
	Model();
	Model(ComPtr<ID3D11Device> device, const ObjReader& model);

	//
	// ����ģ��
	//

	void SetModel(ComPtr<ID3D11Device> device, const ObjReader& model);

	//
	// ��������
	//

	void SetMesh(ComPtr<ID3D11Device> device, const Geometry::MeshData& meshData);
	void SetMesh(ComPtr<ID3D11Device> device, const std::vector<VertexPosNormalTex>& vertices, const std::vector<WORD> indices);
	void SetMesh(ComPtr<ID3D11Device> device, const std::vector<VertexPosNormalTex>& vertices, const std::vector<DWORD> indices);
	void SetMesh(ComPtr<ID3D11Device> device, const VertexPosNormalTex* vertices, UINT vertexCount,
		const void * indices, UINT indexCount, DXGI_FORMAT indexFormat);

	std::vector<ModelPart> modelParts;
	DirectX::BoundingBox boundingBox;
};



#endif