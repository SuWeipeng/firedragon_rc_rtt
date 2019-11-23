#include <AP_Math.h>
#include <stdio.h>
#include <entry.h>
#include "RC_Channel.h"

#if ADC_VCOM_DEBUG != 0
extern rt_device_t vcom;
#endif

RC_Channel::RC_Channel(ADC_HandleTypeDef* hadc)
  : _hadc(hadc)
{
  HAL_ADC_Start_DMA(_hadc, _adc_buf, ADC_BUFF_LEN);
}

uint32_t RC_Channel::get_value(uint8_t channel)
{
  if(channel > ADC_CHANNEL_CNT -1) return 0;
#if ADC_VCOM_DEBUG == 2  
  char buf[30];
  sprintf(buf, "x:%d, y:%d, z:%d\r\n", _adc_buf[0], _adc_buf[2], _adc_buf[1]);
  rt_device_write(vcom, 0, buf, rt_strlen(buf));
#endif  
  return _adc_buf[channel];
}

float RC_Channel::vel_x(int8_t inv)
{
  float    ret = 0.0f;
  uint16_t min = 0;
  uint16_t mid = ADC_CHANNEL_X_MID;
  uint16_t max = ADC_CHANNEL_X_MAX;
#if defined(RC_MODE_1)
  uint16_t val = get_value(0);
#else
  uint16_t val = get_value(3);
#endif
  uint16_t mid_zone_up   = mid + ADC_DEAD_ZONE;
  uint16_t mid_zone_down = mid - ADC_DEAD_ZONE;

  if(abs(val-mid) < ADC_DEAD_ZONE) return 0.0f;

  if(val > mid) {
    ret = (val-mid_zone_up)*(VEL_X_MAX_M_S/(max-mid_zone_up));
  } else {
    ret = (val-mid_zone_down)*(VEL_X_MAX_M_S/(mid_zone_down-min));
  }
  
  if(inv == -1) ret *= inv;
  
#if ADC_VCOM_DEBUG == 1  
  char buf[30];
  sprintf(buf, "vel_x:%.3f\r\n", ret);
  rt_device_write(vcom, 0, buf, rt_strlen(buf));
#endif 
  
  return constrain_float(ret, -VEL_X_MAX_M_S, VEL_X_MAX_M_S);
}

float RC_Channel::vel_y(int8_t inv)
{
  float    ret = 0.0f;
  uint16_t min = 0;
  uint16_t mid = ADC_CHANNEL_Y_MID;
  uint16_t max = ADC_CHANNEL_Y_MAX;
  uint16_t val = get_value(2);
  uint16_t mid_zone_up   = mid + ADC_DEAD_ZONE;
  uint16_t mid_zone_down = mid - ADC_DEAD_ZONE;

  if(abs(val-mid) < ADC_DEAD_ZONE) return 0.0f;

  if(val > mid) {
    ret = (val-mid_zone_up)*(VEL_Y_MAX_M_S/(max-mid_zone_up));
  } else {
    ret = (val-mid_zone_down)*(VEL_Y_MAX_M_S/(mid_zone_down-min));
  }
  
  if(inv == -1) ret *= inv;
  
#if ADC_VCOM_DEBUG == 1  
  char buf[30];
  sprintf(buf, "vel_y:%.3f\r\n", ret);
  rt_device_write(vcom, 0, buf, rt_strlen(buf));
#endif  
  
  return constrain_float(ret, -VEL_Y_MAX_M_S, VEL_Y_MAX_M_S);
}

float RC_Channel::rad_z(int8_t inv)
{
  float    ret = 0.0f;
  uint16_t min = 0;
  uint16_t mid = ADC_CHANNEL_Z_MID;
  uint16_t max = ADC_CHANNEL_Z_MAX;
  uint16_t val = get_value(1);
  uint16_t mid_zone_up   = mid + ADC_DEAD_ZONE;
  uint16_t mid_zone_down = mid - ADC_DEAD_ZONE;

  if(abs(val-mid) < ADC_DEAD_ZONE) return 0.0f;

  if(val > mid) {
    ret = (val-mid_zone_up)*(RAD_Z_MAX_RAD_S/(max-mid_zone_up));
  } else {
    ret = (val-mid_zone_down)*(RAD_Z_MAX_RAD_S/(mid_zone_down-min));
  }
  
  if(inv == -1) ret *= inv;
  
#if ADC_VCOM_DEBUG == 1  
  char buf[30];
  sprintf(buf, "rad_z:%.3f\r\n", ret);
  rt_device_write(vcom, 0, buf, rt_strlen(buf));
#endif 
  
  return constrain_float(ret, -RAD_Z_MAX_RAD_S, RAD_Z_MAX_RAD_S);
}
