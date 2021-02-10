/*! @file : sdk_pph_bme280.h
 * @author  Ernesto Andres Rincon Cruz
 * @version 1.0.0
 * @date    9/02/2021
 * @brief   Driver para sensor de temperatura BME280
 * @details
 *
 */
#ifndef SDK_PPH_BME280_H_
#define SDK_PPH_BME280_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "sdk_hal_i2c0.h"

/*!
 * @addtogroup PERIPHERAL
 * @{
 */
/*!
 * @addtogroup BME280
 * @{
 */
/*******************************************************************************
 * Public Definitions
 ******************************************************************************/
#define BME280_ADDRESS  (0x76) //!< Default BME280 I2C address, if SDO is GND, its 0x76, if SDO is VDD, its 0x77,


enum _bme280_registers{
	REG_ID=0xD0,
	REG_CTRL_HUM=0XF2,
	REG_STATUS,
	REG_CTRL_MEAS,
	REG_CONFIG,
};

/*!
 * @brief The MMA8451 three-axis accelerometer data structure
 *
 */
typedef struct _bme280_data{
	uint8_t  status;
	uint32_t temperatura;
	uint32_t humedad;
	uint32_t presion;
}bme280_data_t;
/*******************************************************************************
 * External vars
 ******************************************************************************/

/*******************************************************************************
 * Public vars
 ******************************************************************************/

/*******************************************************************************
 * Public Prototypes
 ******************************************************************************/
/*!
 * @brief read Who Am I register for BME280 detection
 *
 * @return	execution error code
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * @endcode
 */
status_t bme280WhoAmI(void);

/*!
 * @brief read temperature, humidity and pressure from BME280
 * @param data	data structure pointer
 * @return	execution error code
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * @endcode
 */
status_t	bme280ReadAccel(bme280_data_t *data );

/*!
 * @brief perform initialization of BME280
 * @return	execution error code
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * @endcode
 */
status_t bme280Init(void);

/** @} */ // end of X group
/** @} */ // end of X group

#endif /* SDK_PPH_BME280_H_ */
