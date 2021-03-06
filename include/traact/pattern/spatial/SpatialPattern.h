/*  BSD 3-Clause License
 *
 *  Copyright (c) 2020, FriederPankratz <frieder.pankratz@gmail.com>
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice, this
 *     list of conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *
 *  3. Neither the name of the copyright holder nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 *  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 *  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 *  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/

#ifndef TRAACT_INCLUDE_TRAACT_PATTERN_SPATIAL_SPATIALPATTERN_H_
#define TRAACT_INCLUDE_TRAACT_PATTERN_SPATIAL_SPATIALPATTERN_H_

#include <string>
#include <map>
#include <traact/pattern/Pattern.h>
#include <traact/pattern/spatial/CoordinateSystem.h>
#include <traact/traact_core_export.h>
namespace traact::pattern::spatial {
struct TRAACT_CORE_EXPORT SpatialPattern : public Pattern {
 public:
  typedef typename std::shared_ptr<SpatialPattern> Ptr;
  SpatialPattern(const std::string &name, size_t concurrency);
  SpatialPattern(const Pattern &value);
  SpatialPattern();
  /**
   * Add a node to spatial relationship graph
   * @param name name of node
   */
  SpatialPattern &addCoordianteSystem(const std::string &name, bool is_multi = false);

  /**
   * Add edge between two coordinate systems.
   * Depending on port for:
   * -producer or consumer
   * -data meta type
   * @param source origin of transformation e.g. camera
   * @param destination destination of transformation e.g. marker
   * @param port transformation as data meta type
   */
  SpatialPattern &addEdge(const std::string &source, const std::string &destination, const std::string &port);

  std::map<std::string, CoordinateSystem> coordinate_systems_;
  // set of edges, source name, destination name, port name
  std::set<std::tuple<std::string, std::string, std::string> > edges_;

};

}

#endif //TRAACT_INCLUDE_TRAACT_PATTERN_SPATIAL_SPATIALPATTERN_H_
