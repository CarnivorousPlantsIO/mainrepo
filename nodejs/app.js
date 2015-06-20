console.log('hi');

var azureQueue = require('azure-queue-node');

azureQueue.setDefaultClient({
    accountUrl: 'http://vitormeriat.queue.core.windows.net/',
    accountName: 'carnivorousplants',
    accountKey: 'sKbl4rdIxzFYk2I3Y30vNZLME0KcT2EtCGZ/2pw9dCuY+eZruEnpDKMSYheFGCl0YsfUfS1bmPZDwiuhVSW3Ng=='
});

var queueName = 'telimetria';

require('cylon').robot({
    
    connections: { edison: { adaptor: 'intel-iot' } },
    devices: {
        //list all of the sensors, lights, etc. that you will use
        led: { driver: 'led', pin: A0 },
        led: { driver: 'ledGreen', pin: 6 },
        led: { driver: 'ledRed', pin: 5 },
        led: { driver: 'ledBlue', pin: 7 },
        led: { driver: 'releligado', pin: 8 }
    },
    
    // this is where you write the main part of your app
    work: function (my) {
        every((0.10).second(), function () {
            //my.led.toggle();
            azureQueue.createQueue(queueName, true, cb);
            
            azureQueue.createMessage(queueName, "Hello world Carnivorous Plants!", function (error, result, response) {
                if (!error) {
                    // Message inserted
                }
            });
        });
    }

    
}).start();




//connections: { edison: { adaptor: 'intel-iot' } },
//devices: {
//    //list all of the sensors, lights, etc. that you will use
//    led: { driver: 'led', pin: 13 }
//},

//// this is where you write the main part of your app
//work: function (my) {
//    every((0.1).second(), function () {
//        //my.led.toggle();
//    });
//}