/*
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2011-2014, Willow Garage, Inc.
 *  Copyright (c) 2014-2015, Open Source Robotics Foundation
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Open Source Robotics Foundation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

/** \author Jia Pan */


#ifndef HPP_FCL_BVH_UTILITY_H
#define HPP_FCL_BVH_UTILITY_H

#include <hpp/fcl/BVH/BVH_model.h>


namespace hpp
{
namespace fcl
{
/// @brief Extract the part of the BVHModel that is inside an AABB.
/// A triangle in collision with the AABB is considered inside.
template<typename BV>
BVHModel<BV>* BVHExtract(const BVHModel<BV>& model, const Transform3f& pose, const AABB& aabb) HPP_FCL_DLLAPI;

/// @brief Compute the covariance matrix for a set or subset of points. if ts = null, then indices refer to points directly; otherwise refer to triangles
void getCovariance(Vec3f* ps, Vec3f* ps2, Triangle* ts, unsigned int* indices, int n, Matrix3f& M) HPP_FCL_DLLAPI;

/// @brief Compute the RSS bounding volume parameters: radius, rectangle size and the origin, given the BV axises.
void getRadiusAndOriginAndRectangleSize(Vec3f* ps, Vec3f* ps2, Triangle* ts, unsigned int* indices, int n, const Matrix3f& axes, Vec3f& origin, FCL_REAL l[2], FCL_REAL& r) HPP_FCL_DLLAPI;

/// @brief Compute the bounding volume extent and center for a set or subset of points, given the BV axises.
void getExtentAndCenter(Vec3f* ps, Vec3f* ps2, Triangle* ts, unsigned int* indices, int n, Matrix3f& axes, Vec3f& center, Vec3f& extent) HPP_FCL_DLLAPI;

/// @brief Compute the center and radius for a triangle's circumcircle
void circumCircleComputation(const Vec3f& a, const Vec3f& b, const Vec3f& c, Vec3f& center, FCL_REAL& radius) HPP_FCL_DLLAPI;

/// @brief Compute the maximum distance from a given center point to a point cloud
FCL_REAL maximumDistance(Vec3f* ps, Vec3f* ps2, Triangle* ts, unsigned int* indices, int n, const Vec3f& query) HPP_FCL_DLLAPI;

}

} // namespace hpp

#endif
