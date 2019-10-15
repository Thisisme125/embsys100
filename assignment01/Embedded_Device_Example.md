As a type 1 diabetic, I carry around an insulin pump. This device has dramatically improved my quality of life and that is what I wish to discuss.

![G670 Medtronic Pump](https://github.com/Thisisme125/embsys100/blob/master/assignment01/images/G670.jpg)

The device has two primary functions.
1. Provide insulin delivery either time based or by continiously checking blood sugar and adjusting insulin delivery every interval.
2. Monitor blood sugar levels and use measurements as a feedback loop for insulin adjustment.

The following explains how I believe the system works:

Without the sensor for blood glucose measuring, the insulin pump serves as an alternative insulin delivering device to injuctions. There are two types of insulin delivery modes that the pump needs to deliver. The first mode is bolus, and the amount of insulin it delivers after a mean, and is calculated through the carb ratio to insulin ratio. This number is added in manually, so the microcontroller has to do arithmatic in order to calculate the insulin it needs to deliver.

The second type of delivery mode is basal, and that is the insulin the body needs every hour in order to keep the blood sugar levels produced by the body naturally down. This is delivered once every hour. So there has to be some sort of counter or time checking variable to test when an hour has passed, and deliver insulin accordingly.

The insulin is delivered via a motor. When the motor activates, it slowly squeezes out insulin from the reserviour that is in the pump. I assume that the amount of insulin delivered is based on how much the motor has moved. I also believe that is how the insuilin pump determines how much insulin is remaining in the reserviour, by checking the height of the monitor and translating it to the amount of insulin left.

If the sensor is used, it is attached to the body. There is a microstrip that is inserted in the body that tests the bloodsugar, and it wirelessly transmits the data to the insulin pump. Using that data, the pump will alert the user if his current blood sugar is high or low, and it will automatically give additional or stop giving insulin based on the blood sugar. This dubs the device as an "artificial pancreas".

There are a lot of challenges I can see with this device. There is a lot of data processing going on especially with the sensor on. The pump also has many additional functionalities, such as customizable alarms, saving the dates, saving data collected within the last 30 days, and plotting graphs to name a few. Lots of data is being stored and used on this device.

Another challenge is power. This devices runs on a single AA battery, and it manages to do all what was mentioned above plus it power an LCD screen. The lifetime of the battery is 3 - 4 weeks, which is quite impressive for a device of this nature. The sensor has a rechargeable battery. Most definitely the engineers who designed this device are still looking into way to make the device more efficient, either to use a smaller battery or to have it last longer with the current AA battery.

This device is a very critical system, and any errors in the calculations can result in delivering too much insulin which can result in hypoglycemia. The device should have some firmware level checks in order to endure that does not happen. The device also has a lock feature to ensure that the user does not accidentally push buttons to deliver insulin while the device is in their pocket, or if they are asleep.

Another issue is durability. The device has been designed to withstand a beating. It has to withstand being dropped on accident, falling 3 - 5 feet and hitting the ground. Aside from external durability, the internals must remain undamaged. This includes the circuits, motor, battery, and insulin reserviour. 

Portability is another design issue with this device. They have to design in to be a small enough factor to fit in a pocket. And deciding what electronics can go into the circuits. This present a lot of challenges but thankfully through advancements of technology, chips are getting smaller and more efficient. 

Wireless transmission is how the sensor and the glucose meter interacts. Therefore a robust wireless protocol and strong signal integrity is important. A big issue is if the sensor is reading incorrectly. The device has some built in safety checks to make sure that the blood sugar data it is reading is reasonable. If the device is reading inconsistently for a long period, it will prompt the user to replace the sensor.

Finally, cost reduction is another challenge that the designers must overcome. A device like this has many functions and constraints. Thus part selections and design choices to bring the cost down is very crucial and challenging, but necessary for manufacturabliity and affordability.
