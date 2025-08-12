// Copyright 2021 Oxford Technical Solutions Ltd.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * \file oxts_ins_component.hpp
 * Component wrapper for OxtsIns to support ROS 2 composition
 */

#ifndef OXTS_INS__OXTS_INS_COMPONENT_HPP_
#define OXTS_INS__OXTS_INS_COMPONENT_HPP_

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_components/register_node_macro.hpp>
#include "oxts_ins/convert.hpp"
#include <memory>

namespace oxts_ins
{

class OxtsInsComponent : public OxtsIns
{
public:
  explicit OxtsInsComponent(const rclcpp::NodeOptions & options);
};

} // namespace oxts_ins

#endif // OXTS_INS__OXTS_INS_COMPONENT_HPP_
