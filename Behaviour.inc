<?php

/**
 * Created by PhpStorm.
 * User: Brend
 * Date: 2017/05/21
 * Time: 10:12 AM
 */
require 'Birds.inc';
require 'Flowers.inc';
class Behaviour
{
    const DAYS=1;
    private $hours = array(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24);
    private $display;
    private $status;
    private $birdstatus;

    function __construct()
    {
        self::simulate_day($this->hours,self::DAYS);
    }

    Private function simulate_day($data=array(),$repeat){
        $birds  = new Birds();
        $flower = new Flowers();
        $creation =0;
        for($d=0;$d<$repeat;$d++) {
            $flower->getFlowerTime();
            for ($i = 0; $i < count($data); $i++) {
                $day = $d + 1;

                 $value =  $flower->getFlowerStatus($data[$i]);
                if(strlen($value)>1) {
                    $flower->getRandomCal($value);
                    $creation = $value;
                }
                $display = $flower->display();

                $this->birdstatus = $birds->birdstatus($data[$i]);
                $this->display .= 'Hour ' . $data[$i] . ' of day ' . $day . ' it is ' . $this->sun($data[$i]);
                $this->display .= ' and the birds are currently ' . $this->birdstatus . ' <br/>';
                $this->display .= $display.'<br/>';
                $this->display .= $creation.' flower created <br/><br/>';
                $creation =0;

            }

        }

    }


    function __toString()
    {
        return $this->display;
    }

    Private function sun($time){
        switch ($time){
            case $time<6:
                return $this->status = 'Night';

            case $time>20:
                return $this->status = 'Night';

            default:
                return $this->status = 'Day';
        }
    }



}