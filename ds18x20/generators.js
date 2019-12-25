Blockly.JavaScript['ds18x20_get_temp'] = function(block) {
	var dropdown_pin = block.getFieldValue('pin');
	return ['DEV_IO.DS18x20(' + dropdown_pin + ').getTemperature()', Blockly.JavaScript.ORDER_NONE];
};
