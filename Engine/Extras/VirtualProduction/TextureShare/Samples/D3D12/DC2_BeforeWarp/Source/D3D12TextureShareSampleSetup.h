// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "ITextureShareObject.h"
#include "D3D12AppSetup.h"

namespace TextureShareSample
{
	static FTextureShareObjectDesc ObjectDesc(ETextureShareDeviceType::D3D12, UE::TextureShare::DisplayClusterStrings::DefaultShareName);

	namespace DisplayCluster
	{
		static constexpr auto Viewport1 = TEXT("VP_0");
		static constexpr auto Viewport2 = TEXT("VP_1");
		static constexpr auto Viewport3 = TEXT("VP_3");
	}

	namespace Receive
	{
		namespace Texture1
		{
			// Request to read a resource #1 to a remote process
			static FTextureShareViewportResourceDesc Desc(DisplayCluster::Viewport2, UE::TextureShare::DisplayClusterStrings::Viewport::FinalColor, ETextureShareTextureOp::Read);

			// Container for receive: Texture size are not defined on the user side (values on the UE side are used)
			static FTextureShareResourceD3D12 Resource(EResourceSRV::texture1);
		}

		namespace Texture2
		{
			// Request to read a resource #2 to a remote process
			static FTextureShareViewportResourceDesc Desc(DisplayCluster::Viewport1, UE::TextureShare::DisplayClusterStrings::Viewport::FinalColor, ETextureShareTextureOp::Read);

			// Container for receive: Texture size are not defined on the user side (values on the UE side are used)
			static FTextureShareResourceD3D12 Resource(EResourceSRV::texture2);
		}
	}

	namespace Send
	{
		namespace Texture1
		{
			static FTextureShareViewportResourceDesc Desc(DisplayCluster::Viewport1, UE::TextureShare::DisplayClusterStrings::Viewport::FinalColor, ETextureShareTextureOp::Write);
		}

		namespace Texture2
		{
			static FTextureShareViewportResourceDesc Desc(DisplayCluster::Viewport2, UE::TextureShare::DisplayClusterStrings::Viewport::FinalColor, ETextureShareTextureOp::Write);
		}
	}
};
