#pragma once

#include <atomic>

#include <Eigen/Dense>

#include "ao/render/region.hpp"
#include "ao/gl/core.hpp"

class Evaluator;

typedef Eigen::Array<float, Eigen::Dynamic, Eigen::Dynamic> DepthImage;
typedef Eigen::Array<uint32_t, Eigen::Dynamic, Eigen::Dynamic> NormalImage;

namespace Heightmap
{

/*  A Quad represents a rectangular portion of the screen.  */
typedef std::tuple<size_t, size_t, size_t, size_t> Quad;

/*
 *  Render a height-map image into an array of floats (representing depth)
 *  and the height-map's normals into a shaded image with R, G, B, A packed
 *  into int32_t pixels.
 */
std::pair<DepthImage, NormalImage> Render(
        Evaluator* e, Region r, const std::atomic<bool>& abort);
}
