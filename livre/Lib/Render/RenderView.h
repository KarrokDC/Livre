/* Copyright (c) 2011-2014, EPFL/Blue Brain Project
 *                     Ahmet Bilgili <ahmet.bilgili@epfl.ch>
 *
 * This file is part of Livre <https://github.com/BlueBrain/Livre>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 3.0 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef _RenderView_h_
#define _RenderView_h_

#include <livre/Lib/types.h>
#include <livre/core/Render/View.h>
#include <livre/core/Render/Frustum.h>
#include <livre/core/Dash/DashRenderNode.h>
#include <livre/Lib/Visitor/DFSTraversal.h>
#include <livre/Lib/Configuration/VolumeRendererParameters.h>
#include <livre/Lib/Configuration/EFPrefetchAlgorithmParameters.h>

namespace livre
{

/**
 * The RenderView class implements the expanded frustum algorithm. Frustum is generated by the classes that
 * derives this class.
 */
class RenderView : public View
{
public:

    RenderView( );

    /**
     * Sets the rendering parameters
     * @param volumeRendererParameters Volume rendering parameters.
     * @param prefetchAlgorithmParameters Prefetch algorithm parameters.
     */
    void setParameters(  ConstVolumeRendererParametersPtr volumeRendererParameters,
                         ConstEFPParametersPtr prefetchAlgorithmParameters );

private:

    bool onPreRender_( const GLWidget& widget,
                       const FrameInfo& frameInfo,
                       GenerateRenderingSet& renderListGenerator,
                       Frustum& modifiedFrustum );

    void onPostRender_(  const bool rendered,
                         const GLWidget& widget,
                         const FrameInfo& frameInfo,
                         GenerateRenderingSet& renderListGenerator );

    void generateIteratedFrustum_( GenerateRenderingSet& renderListGenerator,
                                   const Frustum& previousFrustum,
                                   const Frustum& currentFrustum,
                                   Frustum& modifiedFrustum ) const;

    void generateRequest_( const Frustum& currentFrustum,
                           GenerateRenderingSet& renderListGenerator,
                           const uint32_t windowHeight );

    void freeTextures_( const DashNodeVector& renderNodeList );

    DashNodeSet previousVisibleSet_;

    DFSTraversal dfsTraverser_;

    float visibleFrustumScreenSpaceError_;

    float texturePFrustumScreenSpaceError_;

    float dataPFrustumScreenSpaceError_;

    FloatVector prefetchDistanceRatios_;

    VolumeRendererParameters volumeRendererParameters_;

    EFPrefetchAlgorithmParameters prefetchAlgorithmParameters_;
};

}


#endif // _VaporView_h_
