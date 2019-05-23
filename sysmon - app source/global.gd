extends Node

# class member variables go here, for example:
# var a = 2
# var b = "textvar"

var govern = MeterCpu.new()
var meterScale = 1/float(8)*6

func _process(delta):
#	# Called every frame. Delta is time since last frame.
#	# Update game logic here.
	govern.CalcForAllCpu()
