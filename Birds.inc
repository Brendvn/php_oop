<?php

/**
 * Created by PhpStorm.
 * User: Brend
 * Date: 2017/05/21
 * Time: 08:07 AM
 */
class Birds extends Random
{
    const BIRDS=10;
    private $status;
    public static $birdobj = array();
    private $name = '';


    public function birdstatus($data){
        switch ($data){
            case $data>=21:
                return $this->status = 'Sleeping';

            case $data<5:
                return $this->status = 'Sleeping';

            default:
                return $this->status = 'Awake';
        }
    }

    public function __construct()
    {
        for($i=0;$i<self::BIRDS;$i++) {
            $count=$i+1;
            $this->name = 'Bird'.$count;
            array_push(self::$birdobj, array('birds' => array(
                'name' => $this->name,
            )));
        }
    }
}