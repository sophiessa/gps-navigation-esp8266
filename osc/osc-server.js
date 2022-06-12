const osc = require('node-osc');

const serverPort = 1234;
const serverIP = '192.168.0.25';
const oscServer = new osc.Server(serverPort, serverIP);


oscServer.on('message', (msg, rinfo) => {
    console.log('Message coming from ' + rinfo.address + ':' + rinfo.port);
    console.log('Message: ' + msg[1]);
});