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

#ifndef TRAACTTEST_SRC_TRAACT_NETWORK_NETWORKGRAPH_H_
#define TRAACTTEST_SRC_TRAACT_NETWORK_NETWORKGRAPH_H_

#include <memory>
#include <tbb/flow_graph.h>

#include <dataflow/intern/TraactComponentBase.h>
#include <traact/component/ComponentGraph.h>
#include <traact/pattern/instance/PortInstance.h>

#include <traact/buffer/GenericFactoryObject.h>

#include <traact/buffer/TimeDomainManager.h>

namespace traact::dataflow::intern {

class NetworkGraph {

 public:
  typedef typename std::shared_ptr<NetworkGraph> Ptr;

  typedef typename TraactComponentBase::Ptr TraactComponentBasePtr;
  typedef typename component::ComponentGraph::Ptr DefaultComponentGraphPtr;
  typedef typename buffer::TimeDomainManager::Ptr DefaultTimeDomainManagerPtr;

  typedef typename component::Component DefaultComponent;
  typedef typename component::Component::Ptr DefaultComponentPtr;

  typedef typename pattern::instance::PatternInstance DefaultPattern;
  typedef typename DefaultPattern::Ptr DefaultPatternPtr;
  typedef typename pattern::instance::PortInstance::ConstPtr PortPtr;

  NetworkGraph(DefaultComponentGraphPtr component_graph,
               int time_domain,
               std::set<buffer::GenericFactoryObject::Ptr> generic_factory_objects);
  ~NetworkGraph() = default;

  void init();
  void start();
  void stop();
  void teardown();

  tbb::flow::graph &getTBBGraph();

  tbb::flow::sender<TraactMessage> &getSender(PortPtr port);
  tbb::flow::receiver<TraactMessage> &getReceiver(PortPtr port);

 private:

  DefaultComponentGraphPtr component_graph_;
  std::map<int,DefaultTimeDomainManagerPtr> time_domain_manager_;
  const int time_domain_;
  tbb::flow::graph graph_;

  std::set<TraactComponentBasePtr> network_components_;
  std::map<PortPtr, TraactComponentBasePtr> port_to_network_component;

  std::set<buffer::GenericFactoryObject::Ptr> generic_factory_objects_;
};

}
#endif //TRAACTTEST_SRC_TRAACT_NETWORK_NETWORKGRAPH_H_
