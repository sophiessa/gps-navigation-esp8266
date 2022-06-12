const osc = require('node-osc');

const serverPort = 3333;
const serverIP = '192.168.0.25';
const oscServer = new osc.Server(serverPort, serverIP);


oscServer.on('message', (msg, rinfo) => {
    console.log('Received data: ', msg, rinfo);
});