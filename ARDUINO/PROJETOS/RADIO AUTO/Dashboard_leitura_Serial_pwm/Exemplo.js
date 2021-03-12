// This configurations uses serialport lib to catch usb values in serial COM (N) and baudRate
/* eslint-disable node/no-missing-require */
'use strict';

// Use a Readline parser
const SerialPort = require('serialport');
const parsers = SerialPort.parsers;

// Use a `\r\n` as a line terminator
const parser = new parsers.Readline({
  delimiter: '\r\n'
});

const port = new SerialPort('COM3', {
  baudRate: 115200
});

port.pipe(parser);

port.on('open', () => console.log('Port open'));

// parser.on('data', console.log);
parser.on('data', function(data){
    console.log('main.js => retorno =>', data);
    sendToLoopback(data);
});
// The parser will emit any string response


/**
 * This function uses the request lib to sendo request to api loopback
 * @param {*} data 
 */
function sendToLoopback(data) {

    var request = require('request');
    if(data){        
        request.post(
            'http://localhost:3000/api/sender',
            { json: { corrente: data } },
            function (error, response, body) {
                if (!error && response.statusCode == 200) {
                    console.log('Sender to loopback =>', body)
                }
            }
        );        
    } else {
        console.log('No datas !');
    }
}