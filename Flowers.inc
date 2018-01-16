<?php

/**
 * Created by PhpStorm.
 * User: Brend
 * Date: 2017/05/21
 * Time: 08:07 AM
 */


class Flowers extends Random
{
    const FLOWERS=10;
    private $hours = array(0,1,2);
    private $colors = array('red','green','blue');
    private $flowers = array();
    private $name;
    private $flowerobj = array();
    public static $obj = array();
    private $status='';
    private $string='';
    private $count_close=0;
    private $count_open=0;
    private $count_closing=0;
    private $count_opening=0;


    public function __construct()
    {
        for($i=0;$i<self::FLOWERS;$i++){
            $count=$i+1;

            $name = 'Flower'.$count;

            array_push($this->flowerobj, array('flower' =>array(
                'name' => $name,
                'color'=>$this->random($this->colors),
            )));

        }

    }

    /**
     * Gets random open or close time of flower 0-2
     * @return array
     */
    public function getFlowerTime(){
        for ($i=0;$i<count($this->flowerobj);$i++){
            $openinghour = $this->random($this->hours);
            $this->flowerobj[$i]['flower']['opentime']=$openinghour;

            $openinghour = $this->random($this->hours);
            $this->flowerobj[$i]['flower']['closingtime']=$openinghour;
        }

        return $this->flowerobj;
    }

    /**
     * Sets current status of flowers
     * @param int $value
     * @return int|string
     */
    public function getFlowerStatus($value=0){


        if(($value<6) or ($value>22)){
            $this->status = 'Closed';
            $this->flowerobj = $this->changestatus($sub=4,$val='Closed');

        }elseif(($value>8) and ($value<20)){
            $this->status = 'Open';
            $this->flowerobj = $this->changestatus($sub=4,$val='Open');

        }else{
            $this->flowerobj = $this->openclose($value);
        }

        self::$obj = $this->flowerobj;
        $value =  $this->randomvisits($value);
        return $value;
    }

    /**
     * creates the new flower
     * @param $color
     */
    public function getRandomCal($color){
        return $this->addflower($color);
    }


    /**
     * simulates the time it takes for flower to open
     * @param int $time
     * @return array
     */
    private function openclose($time=0){
        switch ($time){
            case $time==6:
                return $this->changestatus(1,'opentime');
            case $time==7:
                return $this->changestatus(1,'opentime');
            case $time==8:
                return $this->changestatus(1,'opentime');
            case $time==20:
                return $this->changestatus(1,'closingtime');
            case $time==21:
                return $this->changestatus(1,'closingtime');
            case $time==22:
                return $this->changestatus(1,'closingtime');
        }


    }

    /**
     * changes status subtract time form open time and closing
     * @param int $sub
     * @param string $val
     * @return array
     */
    private function changestatus($sub=0, $val=''){
        //return $this->flowerobj;
        if($val=='opentime') {
            for ($i = 0; $i < count($this->flowerobj); $i++) {
                $time = $this->flowerobj[$i]['flower'][$val];

                if($time>0){
                    $time = $time-$sub;
                    $this->flowerobj[$i]['flower']['status']='Opening';
                    $this->flowerobj[$i]['flower'][$val]=$time;
                }

                if($time==0){
                    $this->flowerobj[$i]['flower']['status']='Open';
                }

            }
        }
        if($val=='closingtime'){
            for ($i = 0; $i < count($this->flowerobj); $i++) {
                $time = $this->flowerobj[$i]['flower'][$val];

                if($time>0){
                    $time = $time-$sub;
                    $this->flowerobj[$i]['flower']['status']='Closing';
                    $this->flowerobj[$i]['flower'][$val]=$time;
                }

                if($time==0){
                    $this->flowerobj[$i]['flower']['status']='Closed';
                }

            }
        }

        if($sub==4){
            for ($i=0;$i<count($this->flowerobj);$i++){
                $this->flowerobj[$i]['flower']['status']=$val;

            }
            return $this->flowerobj;
        }
        return $this->flowerobj;
    }

    public function display(){

        $this->count_open=0;
        $this->count_close=0;
        $this->count_closing=0;
        $this->count_opening=0;
        $this->string='';
        for ($i=0;$i<count($this->flowerobj);$i++){
            $curstatus = $this->flowerobj[$i]['flower']['status'];
            switch ($curstatus){
                case $curstatus=='Open':
                    $this->count_open = $this->count_open+1;
                    break;
                case $curstatus=='Closed':
                    $this->count_close = $this->count_close+1;
                    break;
                case $curstatus=='Closing':
                    $this->count_closing = $this->count_closing+1;
                    break;
                case $curstatus=='Opening':
                    $this->count_opening = $this->count_opening+1;
                    break;
            }

        }

        return $this->string .= 'Flowers Open '.$this->count_open.' Flowers Opening '.$this->count_opening.' Flowers Closed '.$this->count_close.' Flowers Closing '.$this->count_closing ;

    }


    /**
     * this addes a new flower
     * @param $color
     */
    public function addflower($color){
        $count = count($this->flowerobj)+1 ;
        $arr = array('flower' => array(
            'name' => 'Flower'.$count,
            'color' => $color,
            'opentime' => 0,
            'closingtime'=>0,
            'status'=>'Open',
        ));
        array_push($this->flowerobj,$arr);
    }


}