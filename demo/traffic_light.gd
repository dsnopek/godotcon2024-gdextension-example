extends TrafficLight


func _get_next_light(p_light: TrafficLightType) -> TrafficLightType:
	if p_light == TRAFFIC_LIGHT_STOP:
		return TRAFFIC_LIGHT_GO
	elif p_light == TRAFFIC_LIGHT_GO:
		return TRAFFIC_LIGHT_CAUTION
	elif p_light == TRAFFIC_LIGHT_CAUTION:
		return TRAFFIC_LIGHT_STOP

	return TRAFFIC_LIGHT_STOP
