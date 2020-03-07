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

#ifndef TRAACT_INCLUDE_TRAACT_BUFFER_GENERIC_GENERICCOMPONENTBUFFER_H_
#define TRAACT_INCLUDE_TRAACT_BUFFER_GENERIC_GENERICCOMPONENTBUFFER_H_

#include <tuple>

#include <traact/datatypes.h>
#include <traact/buffer/GenericTimeDomainBuffer.h>
#include <traact/buffer/GenericBufferTypeConversion.h>

namespace traact::buffer {
class GenericComponentBuffer {
 public:
  typedef typename std::shared_ptr<GenericComponentBuffer> Ptr;
  typedef typename GenericTimeDomainBuffer::BufferType TDBufferType;
  GenericComponentBuffer(std::string
                         component_name,
                         GenericTimeDomainBuffer &time_domain_buffer,
                         TDBufferType &input,
                         TDBufferType &output
  )
      : component_name_(std::move(component_name)),
        time_domain_buffer_(time_domain_buffer),
        input_data_(std::move(input)),
        output_data_(std::move(output)) {

  };

  template<typename ReturnType, typename HeaderType>
  const ReturnType &getInput(size_t index) {
    return type_conversion_.asImmutable<ReturnType, HeaderType>(input_data_.at(index), 0);
  }

  template<typename ReturnType, typename HeaderType>
  ReturnType &getOutput(size_t index) {
    return type_conversion_.asMutable<ReturnType, HeaderType>(output_data_.at(index), 0);
  }

  const TimestampType &getTimestamp() const {
    return time_domain_buffer_.getTimestamp();
  }

 private:
  TDBufferType input_data_;
  TDBufferType output_data_;
  std::string component_name_;

  GenericBufferTypeConversion type_conversion_;

  GenericTimeDomainBuffer &time_domain_buffer_;
};
}

#endif //TRAACT_INCLUDE_TRAACT_BUFFER_GENERIC_GENERICCOMPONENTBUFFER_H_