// Copyright 2024 The Autoware Contributors
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

#ifndef REMAINING_DISTANCE_TIME_DISPLAY_HPP_
#define REMAINING_DISTANCE_TIME_DISPLAY_HPP_
#include "overlay_utils.hpp"

#include <QImage>
#include <QString>
#include <rviz_common/properties/color_property.hpp>
#include <rviz_common/properties/float_property.hpp>
#include <rviz_common/properties/int_property.hpp>
#include <rviz_common/ros_topic_display.hpp>

#include <autoware_internal_msgs/msg/mission_remaining_distance_time.hpp>

#include <OgreColourValue.h>
#include <OgreMaterial.h>
#include <OgreTexture.h>

namespace autoware_mission_details_overlay_rviz_plugin
{

class RemainingDistanceTimeDisplay
{
public:
  RemainingDistanceTimeDisplay();
  void drawRemainingDistanceTimeDisplay(QPainter & painter, const QRectF & backgroundRect);
  void updateRemainingDistanceTimeData(
    const autoware_internal_msgs::msg::MissionRemainingDistanceTime::ConstSharedPtr & msg);

private:
  double remaining_distance_;  // Internal variable to store remaining distance
  uint32_t hours_;             // Internal variable to store remaining time hours
  uint32_t minutes_;           // Internal variable to store remaining time minutes
  uint32_t seconds_;           // Internal variable to store remaining time seconds
  QColor gray = QColor(194, 194, 194);
};

}  // namespace autoware_mission_details_overlay_rviz_plugin

#endif  // REMAINING_DISTANCE_TIME_DISPLAY_HPP_