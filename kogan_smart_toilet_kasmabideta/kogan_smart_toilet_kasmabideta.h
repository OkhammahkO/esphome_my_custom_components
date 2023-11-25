// #pragma once

// #include "esphome/components/climate_ir/climate_ir.h"
#include <array>
#include <cstdint>

namespace esphome
{
  namespace kogan_smart_toilet
  {
    // Function              | Bits    | Count | Comment
    // ----------------------|---------|-------|----------------------------------------------------
    // Pronto Preamble       | 01-04   |    4  | Raw data, Carrier frequency (38031.13 Hz), 51 Burst Pairs in Sequence #1, No Sequence #2 (Repeat). Appears to be constant.
    // Lead in burst pairs   | 05-08   |    4  | Assumed, unconfirmed. Appears to be constant.
    // Address               | 09-24   |   16  | Included in checksum. Appears to be constant.
    // Commands              | 25-88   |   64  | Included in checksum
    // Checksum              | 89-104  |   16  | Sum of above, then modulo 256
    // Lead out burst pairs  | 105-106 |   16  | Assumed, unconfirmed. Appears to be constant.

    // Pronto Preamble
    const std::array<uint8_t, 8> PREAMBLE_BITS_1_TO_4 = {0x00, 0x6D, 0x33, 0x00};

    // Lead-in Burst Pairs
    const std::array<uint8_t, 8> LEAD_IN_BURST_PAIRS_BITS_5_TO_8 = {0x74, 0x75, 0x74, 0xAA};

    // Address
    const std::array<uint8_t, 16> ADDRESS_BITS_9_TO_24 = {0x14, 0x40, 0x14, 0x16, 0x14, 0x40, 0x14, 0x16, 0x14, 0x16, 0x14, 0x40, 0x14, 0x40, 0x14, 0x40};

    // Lead out burst pair
    const std::array<uint8_t, 2> LEAD_OUT_BURST_PAIRS_BITS_105_AND_106 = {0x14, 0x81};

    // Command Structure
    // | Short_Name                   | Bit Positions | Bit Count | Description
    // | -----------------------------| --------------| --------- | ----------------------------------------------
    // | Idle Mode                    | 25-26         | 2         | ON if rear, front, dry NOT enabled (aftyer stop button). Required to start some of the presets (Child, Super, etc)
    // | UNKNOWN_BITS_27_AND_28       | 27-28         | 2         | Unknown. Always 1. Could relate to presets, power, or seated (not in app but avaible in scenes?)
    // | Cleaning Mode                | 31-40         | 10        | self_clean, rear, female, dry, auto_wash. Presets not in app: powerful_wash, child, lady_care, rear_massage, female_massage
    // | Spray Water Temp             | 27-28         | 2         | Unknown. Always 1.

    // Idle Mode
    const std::array<uint8_t, 2> IDLE_MODE_BITS_25_AND_26_ON = {0x14, 0x40};
    const std::array<uint8_t, 2> IDLE_MODE_BITS_25_AND_26_OFF = {0x14, 0x16};

    // UNKNOWN_BITS_27_AND_28
    const std::array<uint8_t, 2> UNKNOWN_BITS_27_AND_28 = {0x14, 0x40};

    // Cleaning Mode
    const std::array<uint8_t, 10> CLEANING_MODE_BITS_31_TO_40_REAR = {0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x40, 0x14, 0x16};
    const std::array<uint8_t, 10> CLEANING_MODE_BITS_31_TO_40_DRY = {0x14, 0x16, 0x14, 0x40, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16};
    const std::array<uint8_t, 10> CLEANING_MODE_BITS_31_TO_40_FEMALE = {0x14, 0x16, 0x14, 0x16, 0x14, 0x40, 0x14, 0x16, 0x14, 0x40};
    const std::array<uint8_t, 10> CLEANING_MODE_BITS_31_TO_40_AUTO = {0x14, 0x40, 0x14, 0x16, 0x14, 0x16, 0x14, 0x40, 0x14, 0x16};
    const std::array<uint8_t, 10> CLEANING_MODE_BITS_31_TO_40_SELF_CLEAN = {0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x40};

    // Spray Water Temperature Level
    const std::array<uint8_t, 8> WATER_TEMP_BITS_41_TO_48_LEVEL_1 = {0014, 0016, 0014, 0016, 0014, 0016, 0014, 0016}; // Level 1 in app is room temp, no heating.
    const std::array<uint8_t, 8> WATER_TEMP_BITS_41_TO_48_LEVEL_2 = {0014, 0016, 0014, 0040, 0014, 0016, 0014, 0016}; // Level 2 = Target temp 33°C (per manual)
    const std::array<uint8_t, 8> WATER_TEMP_BITS_41_TO_48_LEVEL_3 = {0014, 0016, 0014, 0040, 0014, 0040, 0014, 0040}; // Level 3 = 36°C
    const std::array<uint8_t, 8> WATER_TEMP_BITS_41_TO_48_LEVEL_4 = {0014, 0040, 0014, 0016, 0014, 0040, 0014, 0016}; // Level 4 = 39°C

    // Occupacy Not Required Flag

    // Fan Speed

    // IR Transmission

    // // State Frame size
    // const uint8_t DAIKIN_STATE_FRAME_SIZE = 19;

    // class DaikinClimate : public climate_ir::ClimateIR
    // {
    // public:
    //   DaikinClimate()
    //       : climate_ir::ClimateIR(DAIKIN_TEMP_MIN, DAIKIN_TEMP_MAX, 1.0f, true, true,
    //                               {climate::CLIMATE_FAN_AUTO, climate::CLIMATE_FAN_LOW, climate::CLIMATE_FAN_MEDIUM,
    //                                 climate::CLIMATE_FAN_HIGH},
    //                               {climate::CLIMATE_SWING_OFF, climate::CLIMATE_SWING_VERTICAL,
    //                                 climate::CLIMATE_SWING_HORIZONTAL, climate::CLIMATE_SWING_BOTH}) {}

    // protected:
    //   // Transmit via IR the state of this climate controller.
    //   void transmit_state() override;
    //   uint8_t operation_mode_();
    //   uint16_t fan_speed_();
    //   uint8_t temperature_();
    //   // Handle received IR Buffer
    //   bool on_receive(remote_base::RemoteReceiveData data) override;
    //   bool parse_state_frame_(const uint8_t frame[]);
    // };

  } // namespace kogan_smart_toilet
} // namespace esphome