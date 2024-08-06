#include "hardware_interfaces/types.h"

#include <vector>

const std::vector<RobotSafetyMode>& all_safety_modes() {
  static const std::vector<RobotSafetyMode> modes = {
      RobotSafetyMode::NONE, RobotSafetyMode::SAFETY_MODE_NONE,
      RobotSafetyMode::SAFETY_MODE_TRUNCATE, RobotSafetyMode::SAFETY_MODE_STOP};
  return modes;
}

const std::vector<RobotOperationMode>& all_operation_modes() {
  static const std::vector<RobotOperationMode> modes = {
      RobotOperationMode::NONE, RobotOperationMode::OPERATION_MODE_CARTESIAN,
      RobotOperationMode::OPERATION_MODE_JOINT};
  return modes;
}

const std::vector<ForceSensingMode>& all_force_sensing_modes() {
  static const std::vector<ForceSensingMode> modes = {
      ForceSensingMode::NONE, ForceSensingMode::FORCE_MODE_ATI,
      ForceSensingMode::FORCE_MODE_ROBOTIQ};
  return modes;
}

template <>
const char* to_string(const RobotSafetyMode e) {
  switch (e) {
    case RobotSafetyMode::NONE:
      return "NONE";
    case RobotSafetyMode::SAFETY_MODE_NONE:
      return "SAFETY_MODE_NONE";
    case RobotSafetyMode::SAFETY_MODE_TRUNCATE:
      return "SAFETY_MODE_TRUNCATE";
    case RobotSafetyMode::SAFETY_MODE_STOP:
      return "SAFETY_MODE_STOP";
    default:
      return "INVALID_ROBOT_SAFETY_MODE";
  }
}

template <>
const char* to_string(const RobotOperationMode e) {
  switch (e) {
    case RobotOperationMode::NONE:
      return "NONE";
    case RobotOperationMode::OPERATION_MODE_CARTESIAN:
      return "OPERATION_MODE_CARTESIAN";
    case RobotOperationMode::OPERATION_MODE_JOINT:
      return "OPERATION_MODE_JOINT";
    default:
      return "INVALID_ROBOT_OPERATION_MODE";
  }
}

template <>
const char* to_string(const ForceSensingMode e) {
  switch (e) {
    case ForceSensingMode::NONE:
      return "NONE";
    case ForceSensingMode::FORCE_MODE_ATI:
      return "FORCE_MODE_ATI";
    case ForceSensingMode::FORCE_MODE_ROBOTIQ:
      return "FORCE_MODE_ROBOTIQ";
    default:
      return "INVALID_FORCE_SENSING_MODE";
  }
}

template <>
RobotSafetyMode string_to_enum(const std::string& string) {
  for (const auto& mode : all_safety_modes()) {
    if (string == to_string(mode)) {
      return mode;
    }
  }

  return RobotSafetyMode::NONE;
}

template <>
RobotOperationMode string_to_enum(const std::string& string) {
  for (const auto& mode : all_operation_modes()) {
    if (string == to_string(mode)) {
      return mode;
    }
  }

  return RobotOperationMode::NONE;
}

template <>
ForceSensingMode string_to_enum(const std::string& string) {
  for (const auto& mode : all_force_sensing_modes()) {
    if (string == to_string(mode)) {
      return mode;
    }
  }

  return ForceSensingMode::NONE;
}