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

#include <traact/component/Component.h>

namespace traact::component {


Component::Component(std::string name, const ComponentType traact_component_type)
      : name_(std::move(name)), traact_component_type_(traact_component_type) {

  }



  const std::string &Component::getName() const {
    return name_;
  }

  const ComponentType &Component::getComponentType() const {
    return traact_component_type_;
  }


  void Component::updateParameter(const nlohmann::json &parameter) {

  }


  bool Component::init() {
    return true;
  }

  bool Component::start() {
    return true;
  }

  bool Component::stop() {
    return true;
  }

  bool Component::teardown() {
    return true;
  }


  bool Component::initializeBuffer(buffer::GenericComponentBuffer &data) {
    return true;
  }


  bool Component::processTimePoint(buffer::GenericComponentBuffer &data) {
    return true;
  }


  void Component::setRequestCallback(const RequestCallbackType &request_callback) {
    request_callback_ = request_callback;
  }

  void Component::setAcquireCallback(const AcquireCallbackType &acquire_callback) {
    acquire_callback_ = acquire_callback;
  }


  void Component::setCommitCallback(const CommitCallbackType &commit_callback) {
    commit_callback_ = commit_callback;
  }


}
