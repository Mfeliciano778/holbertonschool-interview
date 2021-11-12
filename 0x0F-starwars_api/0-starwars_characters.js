#!/usr/bin/node

const req = require('request');
const id = process.argv[2];
const url = `https://swapi.dev/api/films/${id}/`;

req(url, async function (error, response, body)
{
  if (error)
    return console.error(error);

  const charList = JSON.parse(body).characters;

  for (const char of charList)
  {
    await new Promise(function (resolve, reject)
    {
      req(char, function (error, response, body)
      {
        if (error)
          return console.error(error);

        console.log(JSON.parse(body).name);
        resolve();
      });
    });
  }
});
