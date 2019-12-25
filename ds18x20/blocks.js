Blockly.Blocks['ds18x20_get_temp'] = {
	init: function() {
		this.jsonInit({
			"message0": Blockly.Msg.DS18x20_GET_TEMP_MESSAGE,
			"args0": [{
				"type": "field_dropdown",
				"name": "pin",
				"options": [
					[ "OUT1", "26" ],
					[ "OUT2", "27" ],
					[ "DAC1", "25" ],
					[ "18", "18" ],
					[ "19", "19" ],
					[ "23", "23" ],
					[ "17", "17" ]
				]
			}],
			"output": "Number",
			"colour": 180,
			"tooltip": Blockly.Msg.DS18x20_GET_TEMP_TOOLTIP,
			"helpUrl": ""
		});
	}
};
