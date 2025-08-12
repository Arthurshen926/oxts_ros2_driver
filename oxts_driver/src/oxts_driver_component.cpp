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
 * \file oxts_driver_component.cpp
 * Component wrapper implementation for OxtsDriver
 */

#include "oxts_driver/oxts_driver_component.hpp"

namespace oxts_driver
{

OxtsDriverComponent::OxtsDriverComponent(const rclcpp::NodeOptions & options)
: OxtsDriver(options)
{
  RCLCPP_INFO(this->get_logger(), "OxtsDriver component initialized");
}

} // namespace oxts_driver

// Register the component
RCLCPP_COMPONENTS_REGISTER_NODE(oxts_driver::OxtsDriverComponent)
